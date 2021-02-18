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

nts::AGate::AGate(const std::string &type, std::size_t nb_pins, const pin_list_t &input_pins, std::size_t output_pin) noexcept:
    m_type(type), m_links{nb_pins}, m_input_pins{input_pins}, m_output_pin{output_pin}
{
}

void nts::AGate::simulate(std::size_t tick __attribute__((unused)))
{
}

void nts::AGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(m_type, pin);
    m_links[pin - 1] = std::make_pair(&other, otherPin);
}

nts::Tristate nts::AGate::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        const component_link_t &pair = m_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    if (pin == m_output_pin) {
        return computeOutput();
    }
    return nts::UNDEFINED;
}

void nts::AGate::dump() const
{
    std::cout << m_type << " gate component:" << std::endl;

    std::size_t index = 0;
    for (const auto &pair : m_links) {
        std::cout << "-> Pin " << index << ": ";
        if (++index != m_output_pin) {
            if (pair.first) {
                std::cout << "linked to pin " << pair.second << " of a component";
            } else {
                std::cout << "not linked";
            }
        } else {
            std::cout << "Output pin";
        }
        std::cout << std::endl;
    }
}
