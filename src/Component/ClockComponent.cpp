/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent():
    m_actual_tick(0)
{
    m_type = "clock";
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    while (m_actual_tick < tick) {
        m_value = (m_value == nts::UNDEFINED) ? nts::FALSE : static_cast<nts::Tristate>(!m_value);
        ++m_actual_tick;
    }
}
