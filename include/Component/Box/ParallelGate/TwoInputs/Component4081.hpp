/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include "ParallelGateTwoInputsComponent.hpp"
#include "GateAND.hpp"

namespace nts
{
    using Component4081 = ParallelGateTwoInputsComponent<ComponentType::C4081, GateAND>;
}

#endif /* !COMPONENT4081_HPP_ */
