/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNOT
*/

#include "GateNOT.hpp"

namespace nts
{
    GateNOT::GateNOT() noexcept:
        GateOneInput{ComponentType::GateNOT}
    {
    }

    Tristate GateNOT::operation(Tristate a) const noexcept
    {
        if (a == UNDEFINED)
            return UNDEFINED;
        return static_cast<Tristate>(!a);
    }
} // namespace nts
