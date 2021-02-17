/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** TwoInputsGate
*/

#include <algorithm>
#include <iostream>
#include "TwoInputsGate.hpp"

nts::TwoInputsGate::TwoInputsGate(const std::string &type) noexcept: ACalculationComponent(type, 3, {1, 2}, {3})
{
}

nts::TwoInputsGate::~TwoInputsGate()
{
}

void nts::TwoInputsGate::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::TwoInputsGate::computeOutput(std::size_t pin __attribute__((unused)))
{
    return operation(compute(1), compute(2));
}
