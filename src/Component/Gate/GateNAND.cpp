/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateNAND
*/

#include "GateNAND.hpp"

namespace nts
{
    GateNAND::GateNAND() noexcept:
        GateTwoInputs{ComponentType::GateNAND}
    {
    }

    Tristate GateNAND::operation(Tristate a, Tristate b) const noexcept
    {
        if (a == FALSE || b == FALSE)
            return TRUE;
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return FALSE;
    }
} // namespace nts