/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTransmission
*/

#include "GateTransmission.hpp"

nts::GateTransmission::GateTransmission() noexcept:
    AGate("Transmission", 3, {INPUT, CONTROL}, OUTPUT),
    m_buffer{}
{
}

nts::Tristate nts::GateTransmission::computeOutput()
{
    nts::Tristate control = compute(CONTROL);
    nts::Tristate input = compute(INPUT);

    if (control == nts::TRUE) {
        return input;
    }
    if (control == nts::FALSE) {
        return nts::FALSE;
    }
    return m_value;
}
