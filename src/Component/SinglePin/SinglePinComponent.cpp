/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** SinglePinComponent
*/

#include <iostream>
#include "SinglePinComponent.hpp"
#include "BadPinException.hpp"

namespace nts
{
    SinglePinComponent::SinglePinComponent(ComponentType type, Pin::Mode pin_mode) noexcept:
        m_pin{Pin::UNIDIRECTIONAL, pin_mode},
        m_type{type},
        m_value{UNDEFINED}
    {
    }

    Tristate SinglePinComponent::compute(std::size_t pin)
    {
        if (pin != 1)
            throw BadPinException{COMPONENT_TYPE_AS_STRING.at(m_type), pin};
        return computeOutput();
    }

    void SinglePinComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        if (pin != 1)
            throw BadPinException{COMPONENT_TYPE_AS_STRING.at(m_type), pin};
        m_pin.setLinkWithExternalComponent(other, otherPin);
    }

    void SinglePinComponent::dump() const noexcept
    {
        std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << '\n';
        std::cout << "-> Pin 1: " << '\n';
        m_pin.dump();
    }

    Tristate SinglePinComponent::getValue() const noexcept
    {
        return m_value;
    }

    Tristate SinglePinComponent::computeOutput()
    {
        return getValue();
    }
} // namespace nts