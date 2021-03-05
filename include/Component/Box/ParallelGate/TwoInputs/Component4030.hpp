/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4030
*/

#ifndef COMPONENT4030_HPP_
#define COMPONENT4030_HPP_

#include "ParallelGateTwoInputsComponent.hpp"
#include "GateXOR.hpp"

namespace nts
{
    using Component4030 = ParallelGateTwoInputsComponent<ComponentType::C4030, GateXOR>;
}

#endif /* !COMPONENT4030_HPP_ */
