/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateOR
*/

#include "GateOR.hpp"

namespace nts
{
    GateOR::GateOR() noexcept:
        GateTwoInputs{ComponentType::GateOR}
    {
    }

    Tristate GateOR::operation(Tristate a, Tristate b) const noexcept
    {
        if (a == TRUE || b == TRUE)
            return TRUE;
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return FALSE;
    }
} // namespace nts