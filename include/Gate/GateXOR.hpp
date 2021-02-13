/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateXOR
*/

#ifndef GATEXOR_HPP_
#define GATEXOR_HPP_

#include "TwoInputsGate.hpp"

namespace nts
{
    class GateXOR: public nts::TwoInputsGate {
        public:
            GateXOR() noexcept;
            nts::Tristate operation(nts::Tristate a, nts::Tristate b) const final;
    };
}

#endif /* !GATEXOR_HPP_ */
