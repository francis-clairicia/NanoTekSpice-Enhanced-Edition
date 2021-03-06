/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateOR
*/

#include "GateOR.hpp"

nts::GateOR::GateOR() noexcept: GateTwoInputs(ComponentType::GateOR)
{
}

nts::Tristate nts::GateOR::operation(nts::Tristate a, nts::Tristate b) const
{
    if (a == nts::TRUE || b == nts::TRUE)
        return nts::TRUE;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::FALSE;
}