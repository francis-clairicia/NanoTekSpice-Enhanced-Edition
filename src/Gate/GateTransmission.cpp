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

nts::Tristate nts::GateTransmission::operation(nts::Tristate input, nts::Tristate control) const
{
    if (control == nts::TRUE) {
        return input;
    }
    if (control == nts::FALSE) {
        return nts::FALSE;
    }
    return nts::UNDEFINED;
}
