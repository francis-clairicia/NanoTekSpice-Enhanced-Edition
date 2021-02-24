/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#include <iostream>
#include "InputComponent.hpp"

nts::InputComponent::InputComponent() noexcept:
    SinglePinComponent(InputComponentType),
    m_actual_tick{0},
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

void nts::InputComponent::dump() const
{
    nts::SinglePinComponent::dump();
    std::cout << "-> Value: " << m_value << std::endl;
}

void nts::InputComponent::setValue(nts::Tristate value)
{
    m_value_for_next_tick = value;
}
