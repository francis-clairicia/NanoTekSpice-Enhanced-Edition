/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateINVERTER
*/

#ifndef GATEINVERTER_HPP_
#define GATEINVERTER_HPP_

#include "OneInputGate.hpp"

namespace nts
{
    class GateINVERTER: public nts::OneInputGate {
        public:
            GateINVERTER() noexcept;
            nts::Tristate operation(nts::Tristate a) const final;
    };
}

#endif /* !GATEINVERTER_HPP_ */
