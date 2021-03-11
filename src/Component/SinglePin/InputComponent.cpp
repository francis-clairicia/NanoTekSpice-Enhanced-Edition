/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#include <iostream>
#include "InputComponent.hpp"

nts::InputComponent::InputComponent(nts::ComponentType type) noexcept:
    SinglePinComponent(type, nts::Pin::OUTPUT),
    m_actual_tick{~0UL},
    m_value_for_next_tick{nts::UNDEFINED}
{
}

void nts::InputComponent::simulate(std::size_t tick)
{
    if (m_actual_tick != tick) {
        m_actual_tick = tick;
        m_value = m_value_for_next_tick;
    }
}

void nts::InputComponent::setValue(nts::Tristate value) noexcept
{
    m_value_for_next_tick = value;
}
