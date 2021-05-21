/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
