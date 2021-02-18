/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#include <iostream>
#include "InputComponent.hpp"
#include "BadPinException.hpp"

nts::InputComponent::InputComponent() noexcept:
    SinglePinComponent("input")
{
}

void nts::InputComponent::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::BadPinException(m_type, pin);
    return m_value;
}

void nts::InputComponent::dump() const
{
    nts::SinglePinComponent::dump();
    std::cout << "-> Value: " << getValueAsString() << std::endl;
}

void nts::InputComponent::setValue(nts::Tristate value)
{
    m_value = value;
}
