/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateAND
*/

#include "GateAND.hpp"

namespace nts
{
    GateAND::GateAND() noexcept:
        GateTwoInputs{ComponentType::GateAND}
    {
    }

    Tristate GateAND::operation(Tristate a, Tristate b) const noexcept
    {
        if (a == FALSE || b == FALSE)
            return FALSE;
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return TRUE;
    }
} // namespace nts