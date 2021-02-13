/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#include <algorithm>
#include <iostream>
#include "OneInputGate.hpp"
#include "Exception.hpp"

nts::OneInputGate::OneInputGate(const std::string &type) noexcept:
    m_type(type), m_links{std::make_pair(nullptr, 0)}, m_input_pins({1})
{
}

nts::OneInputGate::~OneInputGate()
{
}

void nts::OneInputGate::simulate(std::size_t tick __attribute__((unused)))
{
}

void nts::OneInputGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) == m_input_pins.end())
        throw BadLinkException(m_type, "the pin " + std::to_string(pin) + " is an output pin");
    other.compute(otherPin);
    m_links[pin - 1] = std::make_pair(&other, otherPin);
}

nts::Tristate nts::OneInputGate::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        auto pair = m_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    return operation(compute(1));
}

void nts::OneInputGate::dump() const
{
    std::cout << m_type << " component:" << std::endl;

    std::size_t index = 0;
    for (auto &pair : m_links) {
        std::cout << "-> Pin " << ++index << ": ";
        if (pair.first) {
            std::cout << "linked to pin " << pair.second << " of a component";
        } else {
            std::cout << "not linked";
        }
        std::cout << std::endl;
    }
}
