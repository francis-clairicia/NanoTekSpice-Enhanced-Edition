/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OutputComponent
*/

#include <iostream>
#include "OutputComponent.hpp"
#include "Exception.hpp"

nts::OutputComponent::OutputComponent() noexcept:
    m_link(nullptr), m_link_pin(0), m_name(""), m_value(nts::UNDEFINED)
{
}

nts::OutputComponent::~OutputComponent()
{
}

void nts::OutputComponent::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::BadPinException(m_name, pin);
    m_value = (m_link) ? m_link->compute(m_link_pin) : nts::UNDEFINED;
    return m_value;
}

void nts::OutputComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        throw nts::BadPinException(m_name, pin);
    m_link = &other;
    m_link_pin = otherPin;
}

void nts::OutputComponent::dump() const
{
    std::cout << "OutputComponent '" << m_name << "' with value: " << getValueAsString() << std::endl;
}

const std::string nts::OutputComponent::getValueAsString() const noexcept
{
    for (auto &pair : nts::INPUT_CONVERTER) {
        if (pair.second == m_value)
            return pair.first;
    }
    return std::string();
}

const std::string &nts::OutputComponent::getName() const noexcept
{
    return m_name;
}

void nts::OutputComponent::setName(const std::string &name) noexcept
{
    m_name = name;
}
