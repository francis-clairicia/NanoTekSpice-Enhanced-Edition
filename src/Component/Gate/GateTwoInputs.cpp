/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTwoInputs
*/

#include "GateTwoInputs.hpp"

nts::GateTwoInputs::GateTwoInputs(nts::ComponentType type) noexcept: AGate(type, 3, {1, 2}, 3)
{
}

nts::Tristate nts::GateTwoInputs::computeOutput()
{
    return operation(compute(1), compute(2));
}
