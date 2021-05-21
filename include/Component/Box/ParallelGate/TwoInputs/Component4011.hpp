/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4011
*/

#ifndef COMPONENT4011_HPP_
#define COMPONENT4011_HPP_

#include "ParallelGateTwoInputsComponent.hpp"
#include "GateNAND.hpp"

namespace nts
{
    using Component4011 = ParallelGateTwoInputsComponent<ComponentType::C4011, GateNAND>;
}

#endif /* !COMPONENT4011_HPP_ */
