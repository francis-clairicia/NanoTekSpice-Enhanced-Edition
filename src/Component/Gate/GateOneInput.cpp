/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateOneInput
*/

#include "GateOneInput.hpp"

nts::GateOneInput::GateOneInput(nts::ComponentType type) noexcept: AGate(type, 2, {1}, 2)
{
}

nts::GateOneInput::~GateOneInput()
{
}

nts::Tristate nts::GateOneInput::computeOutput()
{
    return operation(compute(1));
}
