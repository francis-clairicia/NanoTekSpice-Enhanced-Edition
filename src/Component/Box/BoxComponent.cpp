/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** BoxComponent
*/

#include <iostream>
#include "BoxComponent.hpp"
#include "BadPinException.hpp"

namespace nts
{
    BoxComponent::BoxComponent(ComponentType type, std::size_t nb_pins, PinList::Initializer input_pins, PinList::Initializer output_pins) noexcept:
        m_type{type},
        m_actual_tick{~0UL},
        m_pins{nb_pins, input_pins, output_pins}
    {
    }

    void BoxComponent::simulate(std::size_t tick)
    {
        m_actual_tick = tick;
    }

    Tristate BoxComponent::compute(std::size_t pin)
    {
        if (!m_pins.hasPin(pin))
            throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);

        if (m_pins[pin].isInput())
            return FALSE;

        return m_pins[pin].compute(m_actual_tick);
    }

    void BoxComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        if (!m_pins.hasPin(pin))
            throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
        m_pins[pin].setLinkWithExternalComponent(other, otherPin);
    }

    void BoxComponent::dump() const noexcept
    {
        std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << '\n';
        m_pins.dump();
        dumpInternalComponents();
    }

    void BoxComponent::dumpInternalComponents() const noexcept
    {
    }

    void BoxComponent::setLinkInternal(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        if (!m_pins.hasPin(pin))
            throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
        m_pins[pin].setLinkWithInternalComponent(other, otherPin);
    }
} // namespace nts
