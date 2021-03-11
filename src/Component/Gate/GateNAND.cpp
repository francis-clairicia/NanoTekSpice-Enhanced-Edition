/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNAND
*/

#include "GateNAND.hpp"

nts::GateNAND::GateNAND() noexcept: GateTwoInputs(ComponentType::GateNAND)
{
}

nts::Tristate nts::GateNAND::operation(nts::Tristate a, nts::Tristate b) const noexcept
{
    if (a == nts::FALSE || b == nts::FALSE)
        return nts::TRUE;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::FALSE;
}