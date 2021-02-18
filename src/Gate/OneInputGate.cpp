/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#include "OneInputGate.hpp"

nts::OneInputGate::OneInputGate(const std::string &type) noexcept: AGate(type, 2, {1}, 2)
{
}

nts::OneInputGate::~OneInputGate()
{
}

nts::Tristate nts::OneInputGate::computeOutput()
{
    return operation(compute(1));
}
