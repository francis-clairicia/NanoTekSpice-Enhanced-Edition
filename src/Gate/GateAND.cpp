/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateAND
*/

#include "GateAND.hpp"

nts::GateAND::GateAND(std::size_t input_pin1, std::size_t input_pin2): TwoInputsGate(input_pin1, input_pin2)
{
}

nts::Tristate nts::GateAND::operation(nts::Tristate a, nts::Tristate b) const
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return static_cast<nts::Tristate>(a && b);
}