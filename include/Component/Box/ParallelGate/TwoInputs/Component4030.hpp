/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
