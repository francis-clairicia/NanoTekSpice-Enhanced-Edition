/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNOR
*/

#ifndef GATENOR_HPP_
#define GATENOR_HPP_

#include "TwoInputsGate.hpp"

namespace nts
{
    class GateNOR: public nts::TwoInputsGate {
        public:
            enum Pin
            {
                INPUT1 = 1,
                INPUT2 = 2,
                OUTPUT = 3
            };

        public:
            GateNOR() noexcept;
            nts::Tristate operation(nts::Tristate a, nts::Tristate b) const final;
    };
}

#endif /* !GATENOR_HPP_ */
