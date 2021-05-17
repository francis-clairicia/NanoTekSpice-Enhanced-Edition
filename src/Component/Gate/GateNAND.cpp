/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNAND
*/

#include "GateNAND.hpp"

namespace nts
{
    GateNAND::GateNAND() noexcept: GateTwoInputs(ComponentType::GateNAND)
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