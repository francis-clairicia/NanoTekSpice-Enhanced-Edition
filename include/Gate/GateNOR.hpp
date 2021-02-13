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
            GateNOR(std::size_t input_pin1, std::size_t input_pin2);
            nts::Tristate operation(nts::Tristate a, nts::Tristate b) const final;
    };
}

#endif /* !GATENOR_HPP_ */
