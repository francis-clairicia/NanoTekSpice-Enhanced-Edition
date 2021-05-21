/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTwoInputs
*/

#include "GateTwoInputs.hpp"

namespace nts
{
    GateTwoInputs::GateTwoInputs(ComponentType type) noexcept:
        AGate{type, 3, {INPUT1, INPUT2}, OUTPUT}
    {
    }

    Tristate GateTwoInputs::computeOutput()
    {
        return operation(compute(INPUT1), compute(INPUT2));
    }
} // namespace nts
