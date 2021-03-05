/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent():
    InputComponent(ComponentType::Clock),
    m_invert_value{true}
{
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (m_actual_tick != tick) {
        m_actual_tick = tick;
        if (m_invert_value && m_value != nts::UNDEFINED)
            m_value = static_cast<nts::Tristate>(!m_value);
        else
            m_value = m_value_for_next_tick;
        m_invert_value = true;
    }
}

void nts::ClockComponent::setValue(nts::Tristate value)
{
    InputComponent::setValue(value);
    m_invert_value = false;
}
