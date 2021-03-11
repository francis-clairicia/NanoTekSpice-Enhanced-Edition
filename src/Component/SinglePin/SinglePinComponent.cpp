/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SinglePinComponent
*/

#include <iostream>
#include "SinglePinComponent.hpp"
#include "BadPinException.hpp"

nts::SinglePinComponent::SinglePinComponent(nts::ComponentType type, nts::Pin::Mode pin_mode) noexcept:
    m_pin{pin_mode},
    m_type{type},
    m_value{nts::UNDEFINED}
{
}

nts::Tristate nts::SinglePinComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    return computeOutput();
}

void nts::SinglePinComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        throw nts::BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_pin.setLinkWithExternalComponent(other, otherPin);
}

void nts::SinglePinComponent::dump() const noexcept
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << '\n';
    std::cout << "-> Pin 1: " << '\n';
    m_pin.dump();
}

nts::Tristate nts::SinglePinComponent::getValue() const noexcept
{
    return m_value;
}

nts::Tristate nts::SinglePinComponent::computeOutput()
{
    return getValue();
}