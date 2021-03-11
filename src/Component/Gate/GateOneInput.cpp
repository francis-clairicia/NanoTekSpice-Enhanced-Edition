/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateOneInput
*/

#include "GateOneInput.hpp"

nts::GateOneInput::GateOneInput(nts::ComponentType type) noexcept: AGate(type, 2, {INPUT}, OUTPUT)
{
}

nts::Tristate nts::GateOneInput::computeOutput(std::size_t tick)
{
    return operation(m_pins[INPUT].compute(tick));
}
