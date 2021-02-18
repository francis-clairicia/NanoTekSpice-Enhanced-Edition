/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTransmission
*/

#include "GateTransmission.hpp"

nts::GateTransmission::GateTransmission() noexcept: TwoInputsGate("Transmission")
{
}

nts::Tristate nts::GateTransmission::operation(nts::Tristate a, nts::Tristate control) const
{
    if (a == nts::UNDEFINED || control == nts::UNDEFINED)
        return nts::UNDEFINED;
    return (!control) ? nts::UNDEFINED : a;
}
