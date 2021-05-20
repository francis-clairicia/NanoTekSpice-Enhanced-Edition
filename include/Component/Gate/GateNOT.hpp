/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNOT
*/

#ifndef GATENOT_HPP_
#define GATENOT_HPP_

#include "GateOneInput.hpp"

namespace nts
{
    class GateNOT final: public GateOneInput
    {
    public:
        GateNOT() noexcept;
        ~GateNOT() noexcept override = default;

        Tristate operation(Tristate a) const noexcept final;
    };
}

#endif /* !GATENOT_HPP_ */
