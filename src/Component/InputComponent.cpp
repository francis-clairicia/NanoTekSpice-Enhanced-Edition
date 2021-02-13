/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#include <iostream>
#include "InputComponent.hpp"
#include "Exception.hpp"

nts::InputComponent::InputComponent() noexcept:
    m_type("input"),
    m_value(nts::UNDEFINED)
{
}

nts::InputComponent::~InputComponent()
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

void nts::InputComponent::setLink(std::size_t pin __attribute__((unused)), nts::IComponent &other __attribute__((unused)), std::size_t otherPin __attribute__((unused)))
{
    throw nts::BadLinkException(m_type, "It's an input component");
}

void nts::InputComponent::dump() const
{
    std::cout << m_type << " component:" << std::endl;
    std::cout << "-> Value: " << getValueAsString() << std::endl;
}

const std::string nts::InputComponent::getValueAsString() const noexcept
{
    for (auto &pair : nts::INPUT_CONVERTER) {
        if (pair.second == m_value)
            return pair.first;
    }
    return std::string();
}

void nts::InputComponent::setValue(const std::string &value)
{
    auto conversion = nts::INPUT_CONVERTER.find(value);

    if (conversion == nts::INPUT_CONVERTER.end())
        throw InputValueException(value);
    m_value = conversion->second;
}
