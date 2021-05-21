/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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

    Tristate GateOneInput::computeOutput()
    {
        return operation(compute(INPUT));
    }
} // namespace nts