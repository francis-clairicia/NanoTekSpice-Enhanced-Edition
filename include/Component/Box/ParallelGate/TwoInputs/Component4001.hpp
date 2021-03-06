/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4001
*/

#ifndef COMPONENT4001_HPP_
#define COMPONENT4001_HPP_

#include "ParallelGateTwoInputsComponent.hpp"
#include "GateNOR.hpp"

namespace nts
{
    using Component4001 = ParallelGateTwoInputsComponent<ComponentType::C4001, GateNOR>;
}

#endif /* !COMPONENT4001_HPP_ */