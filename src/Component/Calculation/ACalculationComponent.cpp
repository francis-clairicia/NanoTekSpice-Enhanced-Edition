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
    m_type{type},
    m_pins{nb_pins, input_pins, output_pins},
    m_actual_tick{~0UL}
{
    for (std::size_t pin : m_pins.getOutputPins())
        m_output_pins[pin] = nts::UNDEFINED;
}

void nts::ACalculationComponent::simulate(std::size_t tick)
{
    if (m_actual_tick != tick) {
        m_actual_tick = tick;
        computeOutputs(tick);
    }
}

void nts::ACalculationComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (!m_pins.hasPin(pin))
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_pins[pin].setLinkWithExternalComponent(other, otherPin);
}

nts::Tristate nts::ACalculationComponent::compute(std::size_t pin)
{
    if (!m_pins.hasPin(pin))
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    if (m_pins[pin].isInput())
        return nts::FALSE;
    if (m_pins[pin].isOutput())
        return m_output_pins.at(pin);
    return nts::UNDEFINED;
}

void nts::ACalculationComponent::dump() const noexcept
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << '\n';
    m_pins.dump();
}

nts::Tristate nts::ACalculationComponent::computeInternalComponent(nts::IComponent &component, std::size_t pin) const
{
    component.simulate(m_actual_tick);
    return component.compute(pin);
}