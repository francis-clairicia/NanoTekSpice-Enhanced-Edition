/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateXOR
*/

#include "GateXOR.hpp"

nts::GateXOR::GateXOR() noexcept: GateTwoInputs(ComponentType::GateXOR)
{
}

nts::Tristate nts::GateXOR::operation(nts::Tristate a, nts::Tristate b) const
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return static_cast<nts::Tristate>(a != b);
}