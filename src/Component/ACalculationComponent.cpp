/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ACalculationComponent
*/

#include <iostream>
#include <algorithm>
#include "ACalculationComponent.hpp"
#include "BadPinException.hpp"

nts::ACalculationComponent::ACalculationComponent(nts::ComponentType type,
                                                  std::size_t nb_pins,
                                                  const pinList_t &input_pins,
                                                  const pinList_t &output_pins) noexcept:
    m_type{type}, m_input_pins{input_pins},
    m_actual_tick{0}, m_computed{false}, m_links{nb_pins}
{
    for (std::size_t pin : output_pins)
        m_output_pins[pin] = nts::UNDEFINED;
}

void nts::ACalculationComponent::simulate(std::size_t tick)
{
    if (m_actual_tick != tick) {
        m_actual_tick = tick;
        m_computed = false;
        if (m_output_pins.empty())
            computeOutputs();
    }
}

void nts::ACalculationComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_links[pin - 1].component = &other;
    m_links[pin - 1].pin = otherPin;
}

nts::Tristate nts::ACalculationComponent::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        const Link &link = m_links.at(pin - 1);
        if (link.component) {
            link.component->simulate(m_actual_tick);
            return link.component->compute(link.pin);
        }
        return nts::UNDEFINED;
    }
    if (m_output_pins.find(pin) != m_output_pins.end()) {
        if (!m_computed) {
            m_computed = true;
            computeOutputs();
        }
        return m_output_pins.at(pin);
    }
    return nts::UNDEFINED;
}

void nts::ACalculationComponent::dump() const
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << std::endl;

    std::size_t index = 0;
    for (const auto &link : m_links) {
        std::cout << "-> Pin " << ++index << ": ";
        if (m_output_pins.find(index) == m_output_pins.end()) {
            if (link.component) {
                std::cout << "linked to pin " << link.pin << " of a component";
            } else {
                std::cout << "not linked";
            }
        } else {
            std::cout << "Output pin";
        }
        std::cout << std::endl;
    }
}

nts::Tristate nts::ACalculationComponent::computeInternalComponent(IComponent &component, std::size_t pin) const
{
    component.simulate(m_actual_tick);
    return component.compute(pin);
}