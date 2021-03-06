/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** GateTransmission
*/

#include "GateTransmission.hpp"

nts::GateTransmission::GateTransmission() noexcept:
    AGate(ComponentType::GateTransmission, 3, {INPUT, CONTROL}, OUTPUT)
{
}

nts::Tristate nts::GateTransmission::operation(const nts::Tristate &input, const nts::Tristate &control) const noexcept
{
    return (control == nts::TRUE) ? input : nts::UNDEFINED;
}

nts::Tristate nts::GateTransmission::computeOutput()
{
    return operation(compute(INPUT), compute(CONTROL));
}