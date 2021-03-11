/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AGate
*/

#include <algorithm>
#include <iostream>
#include "AGate.hpp"
#include "BadPinException.hpp"

nts::AGate::AGate(nts::ComponentType type, std::size_t nb_pins, const pinList_t &input_pins, std::size_t output_pin) noexcept:
    m_value{nts::UNDEFINED}, m_type{type}, m_actual_tick{~0UL},
    m_links(nb_pins), m_input_pins(input_pins), m_output_pin(output_pin)
{
}

void nts::AGate::simulate(std::size_t tick)
{
    if (m_actual_tick != tick) {
        m_actual_tick = tick;
        m_value = computeOutput();
    }
}

void nts::AGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_links[pin - 1].setLink(other, otherPin);
}

nts::Tristate nts::AGate::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        return m_links.at(pin - 1).compute(m_actual_tick);
    }
    if (pin == m_output_pin) {
        return m_value;
    }
    return nts::UNDEFINED;
}

void nts::AGate::dump() const noexcept
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " gate component:" << '\n';

    std::size_t index = 0;
    for (const auto &link : m_links) {
        std::cout << "-> Pin " << ++index << ": " << '\n';
        link.dump();
    }
}
