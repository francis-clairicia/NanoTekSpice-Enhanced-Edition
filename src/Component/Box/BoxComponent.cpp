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
    m_actual_tick{~0UL}, m_internal_links{nb_pins}, m_external_links{nb_pins}
{
}

void nts::BoxComponent::simulate(std::size_t tick)
{
    m_actual_tick = tick;
}

nts::Tristate nts::BoxComponent::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);

    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        return m_external_links.at(pin - 1).compute(m_actual_tick);
    }
    if (std::find(m_output_pins.begin(), m_output_pins.end(), pin) != m_output_pins.end()) {
        return m_internal_links.at(pin - 1).compute(m_actual_tick);
    }

    return nts::UNDEFINED;
}

void nts::BoxComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_external_links[pin - 1].setLink(other, otherPin);
}

void nts::BoxComponent::dump() const
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << '\n';

    std::size_t index = 0;
    for (const auto &link : m_external_links) {
        std::cout << "-> Pin " << ++index << ": " << '\n';
        link.dump();
    }
    std::cout << "Internal linkage:" << '\n';

    index = 0;
    for (const auto &link : m_internal_links) {
        ++index;
        if (link.hasLinks()) {
            std::cout << "-> Pin " << index << ": " << '\n';
            link.dump();
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
    m_internal_links[pin - 1].setLink(other, otherPin);
}
