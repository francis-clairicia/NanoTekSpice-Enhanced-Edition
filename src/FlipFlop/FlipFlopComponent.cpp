/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** FlipFlopComponent
*/

#include <algorithm>
#include <iostream>
#include "FlipFlopComponent.hpp"
#include "Exception.hpp"

/*
Inputs:
    Pin 3: clock (cl)
    Pin 4: reset (r)
    Pin 5: data  (d)
    Pin 6: set   (s)

Outputs:
    Pin 1: q
    Pin 2: /q (not q)
*/

nts::FlipFlopComponent::FlipFlopComponent() noexcept: AComponent("FlipFlop Component", 6, {3, 4, 5, 6}, {1, 2})
{
}

nts::FlipFlopComponent::~FlipFlopComponent()
{
}

void nts::FlipFlopComponent::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::FlipFlopComponent::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        auto pair = m_external_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    if (pin == 1)
        return operationQ(compute(3), compute(5), compute(4), compute(6));
    return operationNotQ(compute(3), compute(5), compute(4), compute(6));
}

void nts::FlipFlopComponent::dump() const
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

nts::Tristate nts::FlipFlopComponent::operationQ(nts::Tristate cl, nts::Tristate d, nts::Tristate r, nts::Tristate s)
{
    if (cl == nts::UNDEFINED || d == nts::UNDEFINED || r == nts::UNDEFINED || s == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (s)
        return nts::TRUE;
    if (r)
        return nts::FALSE;
    if (cl)
        return d;
    return nts::UNDEFINED;
}

nts::Tristate nts::FlipFlopComponent::operationNotQ(nts::Tristate cl, nts::Tristate d, nts::Tristate r, nts::Tristate s)
{
    if (cl == nts::UNDEFINED || d == nts::UNDEFINED || r == nts::UNDEFINED || s == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (r)
        return nts::TRUE;
    if (s)
        return nts::FALSE;
    if (cl)
        return static_cast<nts::Tristate>(!d);
    return nts::UNDEFINED;
}
