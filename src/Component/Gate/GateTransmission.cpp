/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateTransmission
*/

#include "GateTransmission.hpp"

namespace nts
{
    GateTransmission::GateTransmission() noexcept:
        AGate{ComponentType::GateTransmission, 3, {INPUT, CONTROL}, OUTPUT}
    {
    }

    Tristate GateTransmission::operation(Tristate input, Tristate control) const noexcept
    {
        return (control == TRUE) ? input : UNDEFINED;
    }

    Tristate GateTransmission::computeOutput()
    {
        return operation(compute(INPUT), compute(CONTROL));
    }
} // namespace nts