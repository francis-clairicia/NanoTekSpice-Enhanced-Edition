/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#include <iostream>
#include "InputComponent.hpp"
#include "BadPinException.hpp"
#include "InputValueException.hpp"

nts::InputComponent::InputComponent() noexcept:
    IOComponent("input")
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
    nts::IOComponent::dump();
    std::cout << "-> Value: " << getValueAsString() << std::endl;
}

void nts::InputComponent::setValue(const std::string &value)
{
    auto conversion = TRISTATE_CONVERTER.find(value);

    if (conversion == TRISTATE_CONVERTER.end())
        throw InputValueException(value);
    m_value = conversion->second;
}
