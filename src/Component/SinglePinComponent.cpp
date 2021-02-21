/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SinglePinComponent
*/

#include <iostream>
#include "SinglePinComponent.hpp"
#include "BadPinException.hpp"

static const std::unordered_map<nts::Tristate, std::string> TRISTATE_CONVERTER{
    {nts::FALSE,     "0"},
    {nts::TRUE,      "1"},
    {nts::UNDEFINED, "U"}
};

nts::SinglePinComponent::SinglePinComponent(const std::string &type) noexcept:
    m_link{.component = nullptr, .pin = 0},
    m_type(type),
    m_value(nts::UNDEFINED)
{
}

void nts::SinglePinComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        throw nts::BadPinException(m_type, pin);
    m_link.component = &other;
    m_link.pin = otherPin;
}

void nts::SinglePinComponent::dump() const
{
    std::cout << m_type << " component:" << std::endl;
    std::cout << "-> Pin 1: ";
    if (m_link.component)
        std::cout << "linked to the pin " << m_link.pin << " of a component";
    else
        std::cout << "not linked";
    std::cout << std::endl;
}

const std::string &nts::SinglePinComponent::getValueAsString() const noexcept
{
    return TRISTATE_CONVERTER.at(m_value);
}
