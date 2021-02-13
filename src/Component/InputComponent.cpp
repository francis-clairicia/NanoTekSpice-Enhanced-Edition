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
    m_name(""), m_value(nts::UNDEFINED)
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
        throw nts::BadPinException(m_name, pin);
    return m_value;
}

void nts::InputComponent::setLink(std::size_t pin __attribute__((unused)), nts::IComponent &other __attribute__((unused)), std::size_t otherPin __attribute__((unused)))
{
    throw nts::BadLinkException(m_name, "It's an input component");
}

void nts::InputComponent::dump() const
{
    std::cout << "InputComponent '" << m_name << "' with value: " << getValueAsString() << std::endl;
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

const std::string &nts::InputComponent::getName() const noexcept
{
    return m_name;
}

void nts::InputComponent::setName(const std::string &name) noexcept
{
    m_name = name;
}
