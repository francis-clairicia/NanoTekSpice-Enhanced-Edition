/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateAND
*/

#include "GateAND.hpp"

nts::GateAND::GateAND() noexcept: GateTwoInputs(ComponentType::GateAND)
{
}

nts::Tristate nts::GateAND::operation(const nts::Tristate &a, const nts::Tristate &b) const noexcept
{
    if (a == nts::FALSE || b == nts::FALSE)
        return nts::FALSE;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::TRUE;
}