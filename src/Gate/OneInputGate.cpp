/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#include <algorithm>
#include <iostream>
#include "OneInputGate.hpp"

nts::OneInputGate::OneInputGate(const std::string &type) noexcept: ACalculationComponent(type, 2, {1}, {2})
{
}

nts::OneInputGate::~OneInputGate()
{
}

void nts::OneInputGate::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::OneInputGate::computeOutput(std::size_t pin __attribute__((unused)))
{
    return operation(compute(1));
}
