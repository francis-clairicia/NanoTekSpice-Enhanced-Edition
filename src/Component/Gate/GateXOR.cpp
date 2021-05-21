/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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