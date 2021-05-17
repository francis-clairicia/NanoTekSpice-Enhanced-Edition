/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateOneInput
*/

#include "GateOneInput.hpp"

namespace nts
{
    GateOneInput::GateOneInput(ComponentType type) noexcept: AGate(type, 2, {INPUT}, OUTPUT)
    {
    }

    Tristate GateOneInput::computeOutput(std::size_t tick)
    {
        return operation(m_pins[INPUT].compute(tick));
    }
} // namespace nts