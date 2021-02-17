/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** IOComponent
*/

#include <iostream>
#include "IOComponent.hpp"
#include "BadPinException.hpp"

nts::IOComponent::IOComponent(const std::string &type) noexcept:
    m_link(nullptr),
    m_link_pin(0),
    m_type(type),
    m_value(nts::UNDEFINED)
{
}

void nts::IOComponent::simulate(std::size_t tick __attribute__((unused)))
{
}

void nts::IOComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        throw nts::BadPinException(m_type, pin);
    m_link = &other;
    m_link_pin = otherPin;
}

void nts::IOComponent::dump() const
{
    std::cout << m_type << " component:" << std::endl;
    std::cout << "-> Pin 1: ";
    if (m_link)
        std::cout << "linked to the pin " << m_link_pin << " of a component";
    else
        std::cout << "not linked";
    std::cout << std::endl;
}

std::string nts::IOComponent::getValueAsString() const noexcept
{
    for (auto &pair : nts::INPUT_CONVERTER) {
        if (pair.second == m_value)
            return pair.first;
    }
    return std::string();
}
