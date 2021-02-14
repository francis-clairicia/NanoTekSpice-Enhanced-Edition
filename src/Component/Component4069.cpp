/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4069
*/

#include <algorithm>
#include <iostream>
#include "Component4069.hpp"
#include "GateNOT.hpp"
#include "Exception.hpp"

nts::Component4069::Component4069():
    m_type("4069"),
    m_internal_links{}, m_external_links{},
    m_components{
        std::make_unique<GateNOT>(),
        std::make_unique<GateNOT>(),
        std::make_unique<GateNOT>(),
        std::make_unique<GateNOT>(),
        std::make_unique<GateNOT>(),
        std::make_unique<GateNOT>()
    },
    m_input_pins{1, 3, 5, 9, 11, 13},
    m_output_pins{2, 4, 6, 8, 10, 12}
{
    m_components[0]->setLink(1, *this, 1);
    m_components[0]->setLink(2, *this, 2);
    m_internal_links[2] = std::make_pair(m_components[0].get(), 2);

    m_components[1]->setLink(1, *this, 3);
    m_components[1]->setLink(2, *this, 4);
    m_internal_links[4] = std::make_pair(m_components[1].get(), 2);

    m_components[2]->setLink(1, *this, 5);
    m_components[2]->setLink(2, *this, 6);
    m_internal_links[6] = std::make_pair(m_components[2].get(), 2);

    m_components[3]->setLink(1, *this, 9);
    m_components[3]->setLink(2, *this, 8);
    m_internal_links[8] = std::make_pair(m_components[3].get(), 2);

    m_components[4]->setLink(1, *this, 11);
    m_components[4]->setLink(2, *this, 10);
    m_internal_links[10] = std::make_pair(m_components[4].get(), 2);

    m_components[5]->setLink(1, *this, 13);
    m_components[5]->setLink(2, *this, 12);
    m_internal_links[12] = std::make_pair(m_components[5].get(), 2);
}

nts::Component4069::~Component4069()
{
}

void nts::Component4069::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::Component4069::compute(std::size_t pin)
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

void nts::Component4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(m_type, pin);
    other.compute(otherPin);
    m_external_links[pin - 1] = std::make_pair(&other, otherPin);
}

void nts::Component4069::dump() const
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
    for (auto &component : m_components)
        component->dump();
}
