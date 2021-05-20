/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateXOR
*/

#include "GateXOR.hpp"

namespace nts
{
    GateXOR::GateXOR() noexcept:
        GateTwoInputs{ComponentType::GateXOR}
    {
    }

    Tristate GateXOR::operation(Tristate a, Tristate b) const noexcept
    {
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return static_cast<Tristate>(a != b);
    }
} // namespace nts