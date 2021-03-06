/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNOR
*/

#include "GateNOR.hpp"

nts::GateNOR::GateNOR() noexcept: GateTwoInputs(ComponentType::GateNOR)
{
}

nts::Tristate nts::GateNOR::operation(const nts::Tristate &a, const nts::Tristate &b) const
{
    if (a == nts::TRUE || b == nts::TRUE)
        return nts::FALSE;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::TRUE;
}