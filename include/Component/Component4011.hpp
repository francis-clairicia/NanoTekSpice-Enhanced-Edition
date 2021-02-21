/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4011
*/

#ifndef COMPONENT4011_HPP_
#define COMPONENT4011_HPP_

#include "MultiTwoInputsGateComponent.hpp"
#include "GateNAND.hpp"

namespace nts
{
    using Component4011 = MultiTwoInputsGateComponent<Component4011Type, GateNAND>;
}

#endif /* !COMPONENT4011_HPP_ */
