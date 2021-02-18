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

nts::SumComponent::SumComponent() noexcept: AComponent("SUM", 5, {1, 2, 3}, {4, 5})
{
}

nts::SumComponent::~SumComponent()
{
}

void nts::SumComponent::simulate(std::size_t tick __attribute__((unused)))
{
}
