/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4030
*/

#ifndef COMPONENT4030_HPP_
#define COMPONENT4030_HPP_

#include "MultiTwoInputsGateComponent.hpp"
#include "GateXOR.hpp"

namespace nts
{
    using Component4030 = MultiTwoInputsGateComponent<Component4030Type, GateXOR>;
}

#endif /* !COMPONENT4030_HPP_ */
