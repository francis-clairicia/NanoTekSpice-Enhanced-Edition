/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNOR
*/

#include "GateNOR.hpp"

nts::GateNOR::GateNOR() noexcept: TwoInputsGate("NOR gate")
{
}

nts::Tristate nts::GateNOR::operation(nts::Tristate a, nts::Tristate b) const
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return static_cast<nts::Tristate>(!(a || b));
}