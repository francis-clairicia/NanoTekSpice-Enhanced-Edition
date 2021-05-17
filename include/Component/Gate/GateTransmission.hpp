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

    protected:
        Tristate computeOutput(std::size_t tick) final;
    };
}

#endif /* !GATETRANSMISSION_HPP_ */
