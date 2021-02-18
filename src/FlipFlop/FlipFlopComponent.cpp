/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** FlipFlopComponent
*/

#include <iostream>
#include "FlipFlopComponent.hpp"

/*
Inputs:
    Pin 3: clock (cl)
    Pin 4: reset (r)
    Pin 5: data  (d)
    Pin 6: set   (s)

Outputs:
    Pin 1: q
    Pin 2: /q (not q)
*/

nts::FlipFlopComponent::FlipFlopComponent() noexcept: AComponent("FlipFlop", 6, {3, 4, 5, 6}, {1, 2})
{
}

nts::FlipFlopComponent::~FlipFlopComponent()
{
}

void nts::FlipFlopComponent::simulate(std::size_t tick __attribute__((unused)))
{
}
