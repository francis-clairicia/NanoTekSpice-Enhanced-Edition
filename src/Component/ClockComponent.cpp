/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent():
    InputComponent(),
    m_actual_tick{0}
{
    m_type = ClockComponentType;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (m_value == nts::UNDEFINED) {
        m_actual_tick = tick;
        return;
    }
    bool value = m_value;
    while (m_actual_tick < tick) {
        value = !value;
        ++m_actual_tick;
    }
    m_value = static_cast<nts::Tristate>(value);
}
