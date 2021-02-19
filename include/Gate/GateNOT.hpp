/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNOT
*/

#ifndef GATENOT_HPP_
#define GATENOT_HPP_

#include "OneInputGate.hpp"

namespace nts
{
    class GateNOT: public nts::OneInputGate {
        public:
            enum Pin
            {
                INPUT  = 1,
                OUTPUT = 2,
            };

        public:
            GateNOT() noexcept;
            nts::Tristate operation(nts::Tristate a) const final;
    };
}

#endif /* !GATENOT_HPP_ */
