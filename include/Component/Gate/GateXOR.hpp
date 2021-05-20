/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateXOR
*/

#ifndef GATEXOR_HPP_
#define GATEXOR_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateXOR final: public GateTwoInputs
    {
    public:
        GateXOR() noexcept;
        ~GateXOR() noexcept override = default;

        Tristate operation(Tristate a, Tristate b) const noexcept final;
    };
}

#endif /* !GATEXOR_HPP_ */
