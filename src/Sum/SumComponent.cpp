/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SumComponent
*/

#include <algorithm>
#include <iostream>
#include "SumComponent.hpp"
#include "Exception.hpp"

/*
Inputs:
    Pin 1: input Ai
    Pin 2: input Bi
    Pin 3: input Ci

Outputs:
    Pin 4: output Co
    Pin 5: output Si
*/

nts::SumComponent::SumComponent() noexcept: AComponent("SUM Component", 5, {1, 2, 3}, {4, 5})
{
}

nts::SumComponent::~SumComponent()
{
}

void nts::SumComponent::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::SumComponent::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        auto pair = m_external_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    if (pin == 4)
        return operationCo(compute(1), compute(2), compute(3));
    return operationS(compute(1), compute(2), compute(3));
}

void nts::SumComponent::dump() const
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

nts::Tristate nts::SumComponent::operationCo(nts::Tristate a, nts::Tristate b, nts::Tristate c)
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED || c == nts::UNDEFINED)
        return nts::UNDEFINED;
    return static_cast<nts::Tristate>((!c) ? (a && b) : (a || b));
}

nts::Tristate nts::SumComponent::operationS(nts::Tristate a, nts::Tristate b, nts::Tristate c)
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED || c == nts::UNDEFINED)
        return nts::UNDEFINED;
    return static_cast<nts::Tristate>((a != b) != c);
}
