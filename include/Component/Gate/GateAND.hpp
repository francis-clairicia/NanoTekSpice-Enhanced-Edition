/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateAND
*/

#ifndef GATEAND_HPP_
#define GATEAND_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateAND final: public GateTwoInputs
    {
    public:
        GateAND() noexcept;
        ~GateAND() noexcept override = default;

        Tristate operation(Tristate a, Tristate b) const noexcept final;
    };
}

#endif /* !GATEAND_HPP_ */
