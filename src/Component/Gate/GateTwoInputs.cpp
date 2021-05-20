/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTwoInputs
*/

#include "GateTwoInputs.hpp"

namespace nts
{
    GateTwoInputs::GateTwoInputs(ComponentType type) noexcept:
        AGate{type, 3, {INPUT1, INPUT2}, OUTPUT}
    {
    }

    void GateTwoInputs::computeOutput()
    {
        m_pins.output(OUTPUT) = operation(m_pins.input(INPUT1), m_pins.input(INPUT2));
    }
} // namespace nts
