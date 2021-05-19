/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#include <iostream>
#include "InputComponent.hpp"
#include "constants.hpp"

namespace nts
{
    InputComponent::InputComponent(ComponentType type) noexcept:
        SinglePinComponent(type, Pin::OUTPUT),
        m_actual_tick{NO_TICKS},
        m_value_for_next_tick{UNDEFINED}
    {
    }

    void InputComponent::simulate(std::size_t tick)
    {
        if (m_actual_tick != tick) {
            m_actual_tick = tick;
            m_value = m_value_for_next_tick;
        }
    }

    void InputComponent::setValue(Tristate value) noexcept
    {
        m_value_for_next_tick = value;
    }
} // namespace nts