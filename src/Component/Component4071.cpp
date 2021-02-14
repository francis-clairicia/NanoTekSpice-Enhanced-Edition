/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4071
*/

#include <algorithm>
#include <iostream>
#include "Component4071.hpp"
#include "GateOR.hpp"
#include "Exception.hpp"

nts::Component4071::Component4071():
    m_type("4071"),
    m_internal_links{}, m_external_links{},
    m_gates{
        std::make_unique<GateOR>(),
        std::make_unique<GateOR>(),
        std::make_unique<GateOR>(),
        std::make_unique<GateOR>()
    },
    m_input_pins{1, 2, 5, 6, 8, 9, 12, 13},
    m_output_pins{3, 4, 10, 11}
{
    m_gates[0]->setLink(1, *this, 1);
    m_gates[0]->setLink(2, *this, 2);
    m_gates[0]->setLink(3, *this, 3);
    m_internal_links[3] = std::make_pair(m_gates[0].get(), 3);

    m_gates[1]->setLink(1, *this, 5);
    m_gates[1]->setLink(2, *this, 6);
    m_gates[1]->setLink(3, *this, 4);
    m_internal_links[4] = std::make_pair(m_gates[1].get(), 3);

    m_gates[2]->setLink(1, *this, 8);
    m_gates[2]->setLink(2, *this, 9);
    m_gates[2]->setLink(3, *this, 10);
    m_internal_links[10] = std::make_pair(m_gates[2].get(), 3);

    m_gates[3]->setLink(1, *this, 12);
    m_gates[3]->setLink(2, *this, 13);
    m_gates[3]->setLink(3, *this, 11);
    m_internal_links[11] = std::make_pair(m_gates[3].get(), 3);
}

nts::Component4071::~Component4071()
{
}

void nts::Component4071::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::Component4071::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        auto pair = m_external_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    if (std::find(m_output_pins.begin(), m_output_pins.end(), pin) != m_output_pins.end()) {
        auto pair = m_internal_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    return nts::UNDEFINED;
}

void nts::Component4071::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(m_type, pin);
    other.compute(otherPin);
    m_external_links[pin - 1] = std::make_pair(&other, otherPin);
}

void nts::Component4071::dump() const
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
    std::cout << "Gates:" << std::endl;
    for (auto &component : m_gates)
        component->dump();
}
