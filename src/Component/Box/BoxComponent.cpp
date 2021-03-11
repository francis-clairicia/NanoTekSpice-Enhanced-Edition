/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** BoxComponent
*/

#include <iostream>
#include "BoxComponent.hpp"
#include "BadPinException.hpp"

nts::BoxComponent::BoxComponent(nts::ComponentType type, std::size_t nb_pins, const pinList_t &input_pins, const pinList_t &output_pins) noexcept:
    m_type{type},
    m_actual_tick{~0UL},
    m_pins{nb_pins, input_pins, output_pins}
{
}

void nts::BoxComponent::simulate(std::size_t tick)
{
    m_actual_tick = tick;
}

nts::Tristate nts::BoxComponent::compute(std::size_t pin)
{
    if (!m_pins.hasPin(pin))
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);

    if (m_pins[pin] == nts::Pin::INPUT)
        return nts::FALSE;

    return m_pins[pin].compute(m_actual_tick);
}

void nts::BoxComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (!m_pins.hasPin(pin))
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_pins[pin].setLinkWithExternalComponent(other, otherPin);
}

void nts::BoxComponent::dump() const noexcept
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << '\n';
    m_pins.dump();
    dumpInternalComponents();
}

void nts::BoxComponent::dumpInternalComponents() const noexcept
{
}

void nts::BoxComponent::setLinkInternal(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (!m_pins.hasPin(pin))
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_pins[pin].setLinkWithInternalComponent(other, otherPin);
}
