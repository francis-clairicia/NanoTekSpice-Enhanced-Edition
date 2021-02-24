/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** BoxComponent
*/

#include <algorithm>
#include <iostream>
#include "BoxComponent.hpp"
#include "BadPinException.hpp"

nts::BoxComponent::BoxComponent(nts::ComponentType type, std::size_t nb_pins, const pinList_t &input_pins, const pinList_t &output_pins) noexcept:
    m_type{type}, m_input_pins{input_pins}, m_output_pins{output_pins},
    m_actual_tick{0}, m_internal_links{nb_pins}, m_external_links{nb_pins}
{
}

void nts::BoxComponent::simulate(std::size_t tick)
{
    if (m_actual_tick != tick) {
        m_actual_tick = tick;
        std::for_each(m_input_pins.begin(), m_input_pins.end(), [this, &tick](std::size_t pin){
            if (m_external_links[pin - 1].component) {
                m_external_links[pin - 1].component->simulate(tick);
            }
        });
        std::for_each(m_internal_links.begin(), m_internal_links.end(), [&tick](nts::Link &link){
            if (link.component) {
                link.component->simulate(tick);
            }
        });
    }
}

nts::Tristate nts::BoxComponent::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        const Link &link = m_external_links.at(pin - 1);
        return (link.component) ? link.component->compute(link.pin) : nts::UNDEFINED;
    }
    if (std::find(m_output_pins.begin(), m_output_pins.end(), pin) != m_output_pins.end()) {
        const Link &link = m_internal_links.at(pin - 1);
        return (link.component) ? link.component->compute(link.pin) : nts::UNDEFINED;
    }
    return nts::UNDEFINED;
}

void nts::BoxComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_external_links[pin - 1].component = &other;
    m_external_links[pin - 1].pin = otherPin;
}

void nts::BoxComponent::dump() const
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << std::endl;

    std::size_t index = 0;
    for (const auto &link : m_external_links) {
        std::cout << "-> Pin " << ++index << ": ";
        if (link.component) {
            std::cout << "linked to pin " << link.pin << " of a component";
        } else {
            std::cout << "not linked";
        }
        std::cout << std::endl;
    }
    std::cout << "Internal linkage:" << std::endl;

    index = 0;
    for (const auto &link : m_internal_links) {
        ++index;
        if (link.component) {
            std::cout << "-> Pin " << index << ": " << "linked to pin " << link.pin << " of a component" << std::endl;
        }
    }
    dumpInternalComponents();
}

void nts::BoxComponent::dumpInternalComponents() const
{
}

void nts::BoxComponent::setLinkInternal(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_internal_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_internal_links[pin - 1].component = &other;
    m_internal_links[pin - 1].pin = otherPin;
}
