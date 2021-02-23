/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateAND
*/

#ifndef GATEAND_HPP_
#define GATEAND_HPP_

#include "TwoInputsGate.hpp"

namespace nts
{
    class GateAND: public nts::TwoInputsGate {
        public:
            GateAND() noexcept;
            nts::Tristate operation(nts::Tristate a, nts::Tristate b) const final;
    };
}

#endif /* !GATEAND_HPP_ */
