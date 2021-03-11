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
    class GateNOR: public nts::GateTwoInputs {
        public:
            GateNOR() noexcept;
            ~GateNOR() noexcept = default;

            nts::Tristate operation(nts::Tristate a, nts::Tristate b) const noexcept final;
    };
}

#endif /* !GATENOR_HPP_ */
