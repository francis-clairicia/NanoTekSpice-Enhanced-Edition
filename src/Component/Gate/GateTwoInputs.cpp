/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTwoInputs
*/

#include "GateTwoInputs.hpp"

namespace nts
{
    GateTwoInputs::GateTwoInputs(ComponentType type) noexcept: AGate(type, 3, {INPUT1, INPUT2}, OUTPUT)
    {
    }

    Tristate GateTwoInputs::computeOutput(std::size_t tick)
    {
        return operation(m_pins[INPUT1].compute(tick), m_pins[INPUT2].compute(tick));
    }
} // namespace nts
