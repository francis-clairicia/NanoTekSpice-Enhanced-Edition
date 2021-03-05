/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent(nts::ComponentType type) noexcept:
    SinglePinComponent(type)
{
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    m_value = m_pin.compute(tick);
}

