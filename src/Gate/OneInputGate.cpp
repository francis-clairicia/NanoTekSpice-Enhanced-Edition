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

nts::OneInputGate::OneInputGate(const std::string &type) noexcept: AComponent(type, 2, {1}, {2})
{
}

nts::OneInputGate::~OneInputGate()
{
}

void nts::OneInputGate::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::OneInputGate::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        auto pair = m_external_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    return operation(compute(1));
}

void nts::OneInputGate::dump() const
{
    std::cout << m_type << " component:" << std::endl;

    std::size_t index = 0;
    for (auto &pair : m_external_links) {
        std::cout << "-> Pin " << ++index << ": ";
        if (pair.first) {
            std::cout << "linked to pin " << pair.second << " of a component";
        } else {
            std::cout << "not linked";
        }
        std::cout << std::endl;
    }
}
