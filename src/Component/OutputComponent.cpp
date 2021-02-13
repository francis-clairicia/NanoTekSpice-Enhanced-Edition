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
    m_link(nullptr), m_link_pin(0), m_type("output"), m_value(nts::UNDEFINED)
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
        throw nts::BadPinException(m_type, pin);
    m_value = (m_link) ? m_link->compute(m_link_pin) : nts::UNDEFINED;
    return m_value;
}

void nts::OutputComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        throw nts::BadPinException(m_type, pin);
    m_link = &other;
    m_link_pin = otherPin;
}

void nts::OutputComponent::dump() const
{
    std::cout << m_type << " component:" << std::endl;
    std::cout << "-> Pin 1: ";
    if (m_link)
        std::cout << "linked to the pin " << m_link_pin << " of a component";
    else
        std::cout << "not linked";
    std::cout << std::endl;
}

const std::string nts::OutputComponent::getValueAsString() const noexcept
{
    for (auto &pair : nts::INPUT_CONVERTER) {
        if (pair.second == m_value)
            return pair.first;
    }
    return std::string();
}
