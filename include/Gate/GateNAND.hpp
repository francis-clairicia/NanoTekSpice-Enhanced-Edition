/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNAND
*/

#ifndef GATENAND_HPP_
#define GATENAND_HPP_

#include "TwoInputsGate.hpp"

namespace nts
{
    class GateNAND: public nts::TwoInputsGate {
        public:
            GateNAND() noexcept;
            nts::Tristate operation(nts::Tristate a, nts::Tristate b) const final;
    };
}

#endif /* !GATENAND_HPP_ */
