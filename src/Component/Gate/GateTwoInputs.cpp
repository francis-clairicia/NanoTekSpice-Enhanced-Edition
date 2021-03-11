/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTwoInputs
*/

#include "GateTwoInputs.hpp"

nts::GateTwoInputs::GateTwoInputs(nts::ComponentType type) noexcept: AGate(type, 3, {INPUT1, INPUT2}, OUTPUT)
{
}

nts::Tristate nts::GateTwoInputs::computeOutput(std::size_t tick)
{
    return operation(m_pins[INPUT1].compute(tick), m_pins[INPUT2].compute(tick));
}
