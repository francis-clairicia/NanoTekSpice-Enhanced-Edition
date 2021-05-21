/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateTransmission
*/

#ifndef GATETRANSMISSION_HPP_
#define GATETRANSMISSION_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateTransmission: public AGate
    {
    public:
        enum PinName
        {
            INPUT   = 1,
            CONTROL = 2,
            OUTPUT  = 3
        };

    public:
        GateTransmission() noexcept;
        ~GateTransmission() noexcept override = default;

        Tristate operation(Tristate input, Tristate control) const noexcept;

    private:
        Tristate computeOutput() final;
    };
}

#endif /* !GATETRANSMISSION_HPP_ */
