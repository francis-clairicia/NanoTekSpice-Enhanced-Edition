/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateOneInput
*/

#include "GateOneInput.hpp"

namespace nts
{
    GateOneInput::GateOneInput(ComponentType type) noexcept:
        AGate{type, 2, {INPUT}, OUTPUT}
    {
    }

    void GateOneInput::computeOutput()
    {
        m_pins.output(OUTPUT) = operation(m_pins.input(INPUT));
    }
} // namespace nts