/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AGate
*/

#include <algorithm>
#include <iostream>
#include "AGate.hpp"
#include "constants.hpp"

namespace nts
{
    AGate::AGate(ComponentType type, std::size_t nb_pins, PinList::Initializer input_pins, std::size_t output_pin) noexcept:
        m_value{UNDEFINED},
        m_type{type},
        m_pins{type, nb_pins, input_pins, {output_pin}},
        m_actual_tick{NO_TICKS}
    {
    }

    void AGate::simulate(std::size_t tick)
    {
        if (m_actual_tick != tick) {
            m_actual_tick = tick;
            m_value = computeOutput(tick);
        }
    }

    void AGate::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        m_pins[pin].setLinkWithExternalComponent(other, otherPin);
    }

    Tristate AGate::compute(std::size_t pin)
    {
        if (m_pins[pin].isInput()) {
            return FALSE;
        }
        if (m_pins[pin].isOutput()) {
            return m_value;
        }
        return UNDEFINED;
    }

    void AGate::dump() const noexcept
    {
        std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " gate component:" << '\n';
        m_pins.dump();
    }
} // namespace nts
