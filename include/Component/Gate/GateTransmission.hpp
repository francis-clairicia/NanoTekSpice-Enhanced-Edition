/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** GateTransmission
*/

#ifndef GATETRANSMISSION_HPP_
#define GATETRANSMISSION_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateTransmission: public nts::AGate {
        public:
            enum PinName
            {
                INPUT   = 1,
                CONTROL = 2,
                OUTPUT  = 3
            };

        public:
            GateTransmission() noexcept;

            nts::Tristate operation(const nts::Tristate &input, const nts::Tristate &control) const noexcept;

        protected:
            nts::Tristate computeOutput() final;
    };
}

#endif /* !GATETRANSMISSION_HPP_ */
