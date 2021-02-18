/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SumComponent
*/

#include <algorithm>
#include <iostream>
#include "SumComponent.hpp"

/*
Inputs:
    Pin 1: input Ai
    Pin 2: input Bi
    Pin 3: input Ci

Outputs:
    Pin 4: output Co
    Pin 5: output Si
*/

nts::SumComponent::SumComponent() noexcept: ACalculationComponent("SUM", 5, {1, 2, 3}, {4, 5})
{
}

nts::SumComponent::~SumComponent()
{
}

void nts::SumComponent::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::SumComponent::computeOutput(std::size_t pin)
{
    if (pin == 4)
        return operationCo(compute(1), compute(2), compute(3));
    return operationS(compute(1), compute(2), compute(3));
}

nts::Tristate nts::SumComponent::operationCo(nts::Tristate a, nts::Tristate b, nts::Tristate c)
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED || c == nts::UNDEFINED)
        return nts::UNDEFINED;
    return static_cast<nts::Tristate>((!c) ? (a && b) : (a || b));
}

nts::Tristate nts::SumComponent::operationS(nts::Tristate a, nts::Tristate b, nts::Tristate c)
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED || c == nts::UNDEFINED)
        return nts::UNDEFINED;
    return static_cast<nts::Tristate>((a != b) != c);
}
