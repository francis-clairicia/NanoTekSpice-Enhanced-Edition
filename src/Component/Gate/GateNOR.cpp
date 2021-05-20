/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNOR
*/

#include "GateNOR.hpp"

namespace nts
{
    GateNOR::GateNOR() noexcept:
        GateTwoInputs{ComponentType::GateNOR}
    {
    }

    Tristate GateNOR::operation(Tristate a, Tristate b) const noexcept
    {
        if (a == TRUE || b == TRUE)
            return FALSE;
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return TRUE;
    }
} // namespace nts
