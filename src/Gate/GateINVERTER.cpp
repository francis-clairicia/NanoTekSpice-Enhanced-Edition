/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateINVERTER
*/

#include "GateINVERTER.hpp"

nts::GateINVERTER::GateINVERTER(std::size_t input_pin): OneInputGate(input_pin)
{
}

nts::Tristate nts::GateINVERTER::operation(nts::Tristate a) const
{
    if (a == nts::UNDEFINED)
        return nts::UNDEFINED;
    return static_cast<nts::Tristate>(!a);
}