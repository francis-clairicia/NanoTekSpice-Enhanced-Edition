/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTransmission
*/

#ifndef GATETRANSMISSION_HPP_
#define GATETRANSMISSION_HPP_

#include "TwoInputsGate.hpp"

namespace nts
{
    class GateTransmission: public nts::TwoInputsGate {
        public:
            enum Pin
            {
                INPUT   = 1,
                CONTROL = 2,
                OUTPUT  = 3
            };

        public:
            GateTransmission() noexcept;

            nts::Tristate operation(nts::Tristate a, nts::Tristate control) const final;
    };
}

#endif /* !GATETRANSMISSION_HPP_ */
