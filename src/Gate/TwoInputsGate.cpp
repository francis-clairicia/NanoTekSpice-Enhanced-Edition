/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** TwoInputsGate
*/

#include "TwoInputsGate.hpp"

nts::TwoInputsGate::TwoInputsGate(nts::ComponentType type) noexcept: AGate(type, 3, {1, 2}, {3})
{
}

nts::TwoInputsGate::~TwoInputsGate()
{
}

nts::Tristate nts::TwoInputsGate::computeOutput(std::size_t pin __attribute__((unused)))
{
    return operation(compute(1), compute(2));
}
