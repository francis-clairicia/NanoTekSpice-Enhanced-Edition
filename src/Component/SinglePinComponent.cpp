/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SinglePinComponent
*/

#include <iostream>
#include "SinglePinComponent.hpp"
#include "BadPinException.hpp"

nts::SinglePinComponent::SinglePinComponent(nts::ComponentType type) noexcept:
    m_link{.component = nullptr, .pin = 0},
    m_type{type},
    m_value{nts::UNDEFINED}
{
}

nts::Tristate nts::SinglePinComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    return m_value;
}

void nts::SinglePinComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        throw nts::BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_link.component = &other;
    m_link.pin = otherPin;
}

void nts::SinglePinComponent::dump() const
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << std::endl;
    std::cout << "-> Pin 1: ";
    if (m_link.component)
        std::cout << "linked to the pin " << m_link.pin << " of a component";
    else
        std::cout << "not linked";
    std::cout << std::endl;
}
