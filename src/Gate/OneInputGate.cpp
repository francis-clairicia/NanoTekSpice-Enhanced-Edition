/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#include "OneInputGate.hpp"

nts::OneInputGate::OneInputGate(nts::ComponentType type) noexcept: AGate(type, 2, {1}, {2})
{
}

nts::OneInputGate::~OneInputGate()
{
}

nts::Tristate nts::OneInputGate::computeOutput(std::size_t pin __attribute__((unused)))
{
    return operation(compute(1));
}
