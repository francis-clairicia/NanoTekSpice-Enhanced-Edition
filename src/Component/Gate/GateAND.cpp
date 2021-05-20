/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
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