/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
