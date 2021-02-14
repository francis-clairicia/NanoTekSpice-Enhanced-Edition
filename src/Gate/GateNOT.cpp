/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNOT
*/

#include "GateNOT.hpp"

nts::GateNOT::GateNOT() noexcept: OneInputGate("NOT gate")
{
}

nts::Tristate nts::GateNOT::operation(nts::Tristate a) const
{
    if (a == nts::UNDEFINED)
        return nts::UNDEFINED;
    return static_cast<nts::Tristate>(!a);
}