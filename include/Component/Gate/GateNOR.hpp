/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNOR
*/

#ifndef GATENOR_HPP_
#define GATENOR_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateNOR final: public GateTwoInputs
    {
    public:
        GateNOR() noexcept;
        ~GateNOR() noexcept override = default;

        Tristate operation(Tristate a, Tristate b) const noexcept final;
    };
}

#endif /* !GATENOR_HPP_ */
