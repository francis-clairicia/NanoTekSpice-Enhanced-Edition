/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateOR
*/

#ifndef GATEOR_HPP_
#define GATEOR_HPP_

#include "TwoInputsGate.hpp"

namespace nts
{
    class GateOR: public nts::TwoInputsGate {
        public:
            GateOR(std::size_t input_pin1, std::size_t input_pin2);
            nts::Tristate operation(nts::Tristate a, nts::Tristate b) const final;
    };
}

#endif /* !GATEOR_HPP_ */
