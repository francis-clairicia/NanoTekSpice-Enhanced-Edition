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

nts::AGate::AGate(const std::string &type, std::size_t nb_pins, const pinList_t &input_pins, std::size_t output_pin) noexcept:
    m_value(nts::UNDEFINED), m_type(type), m_actual_tick(0), m_computed(false),
    m_links{nb_pins}, m_input_pins{input_pins}, m_output_pin{output_pin}
{
}

void nts::AGate::simulate(std::size_t tick)
{
    if (m_actual_tick < tick) {
        m_computed = false;
        m_actual_tick = tick;
    }
}

void nts::AGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(m_type, pin);
    m_links[pin - 1].component = &other;
    m_links[pin - 1].pin = otherPin;
}

nts::Tristate nts::AGate::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        const Link &link = m_links.at(pin - 1);
        return (link.component) ? link.component->compute(link.pin) : nts::UNDEFINED;
    }
    if (pin == m_output_pin) {
        if (!m_computed) {
            m_computed = true;
            m_value = computeOutput();
        }
        return m_value;
    }
    return nts::UNDEFINED;
}

void nts::AGate::dump() const
{
    std::cout << m_type << " gate component:" << std::endl;

    std::size_t index = 0;
    for (const auto &link : m_links) {
        std::cout << "-> Pin " << index << ": ";
        if (++index != m_output_pin) {
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
