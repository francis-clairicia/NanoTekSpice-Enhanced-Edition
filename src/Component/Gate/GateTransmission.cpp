/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** GateTransmission
*/

#include "GateTransmission.hpp"

namespace nts
{
    GateTransmission::GateTransmission() noexcept:
        AGate{ComponentType::GateTransmission, 3, {INPUT, CONTROL}, OUTPUT}
    {
    }

    Tristate GateTransmission::operation(Tristate input, Tristate control) const noexcept
    {
        return (control == TRUE) ? input : UNDEFINED;
    }

    void GateTransmission::computeOutput()
    {
        m_pins.output(OUTPUT) = operation(m_pins.input(INPUT), m_pins.input(CONTROL));
    }
} // namespace nts