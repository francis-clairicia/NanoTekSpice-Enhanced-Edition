/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNAND
*/

#ifndef GATENAND_HPP_
#define GATENAND_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateNAND final: public GateTwoInputs
    {
    public:
        GateNAND() noexcept;
        ~GateNAND() noexcept override = default;

        Tristate operation(Tristate a, Tristate b) const noexcept final;
    };
}

#endif /* !GATENAND_HPP_ */
