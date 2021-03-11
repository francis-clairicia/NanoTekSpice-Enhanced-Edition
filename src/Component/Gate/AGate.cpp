/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AGate
*/

#include <algorithm>
#include <iostream>
#include "AGate.hpp"
#include "BadPinException.hpp"

nts::AGate::AGate(nts::ComponentType type, std::size_t nb_pins, const pinList_t &input_pins, std::size_t output_pin) noexcept:
    m_value{nts::UNDEFINED},
    m_type{type},
    m_pins{nb_pins, input_pins, {output_pin}},
    m_actual_tick{~0UL}
{
}

void nts::AGate::simulate(std::size_t tick)
{
    if (m_actual_tick != tick) {
        m_actual_tick = tick;
        m_value = computeOutput(tick);
    }
}

void nts::AGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (!m_pins.hasPin(pin))
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_pins[pin].setLinkWithExternalComponent(other, otherPin);
}

nts::Tristate nts::AGate::compute(std::size_t pin)
{
    if (!m_pins.hasPin(pin))
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    if (m_pins[pin] == nts::Pin::INPUT) {
        return nts::FALSE;
    }
    if (m_pins[pin] == nts::Pin::OUTPUT) {
        return m_value;
    }
    return nts::UNDEFINED;
}

void nts::AGate::dump() const noexcept
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " gate component:" << '\n';
    m_pins.dump();
}
