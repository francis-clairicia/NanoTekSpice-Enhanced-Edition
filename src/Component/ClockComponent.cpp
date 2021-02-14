/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent():
    m_actual_tick(0), m_gate(std::make_unique<GateNOT>())
{
    m_type = "clock";
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    while (m_actual_tick < tick) {
        if (m_value == nts::UNDEFINED)
            m_value = nts::FALSE;
        else
            m_value = m_gate->operation(m_value);
    }
}
