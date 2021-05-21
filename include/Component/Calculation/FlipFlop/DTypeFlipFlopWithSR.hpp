/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** DTypeFlipFlopWithSR
*/

#ifndef DTYPEFLIPFLOPWITHSR_HPP_
#define DTYPEFLIPFLOPWITHSR_HPP_

#include "ACalculationComponent.hpp"

namespace nts
{
    class DTypeFlipFlopWithSR final: public ACalculationComponent
    {
    public:
        enum PinName
        {
            Q     = 1,
            Qn    = 2,
            CLOCK = 3,
            RESET = 4,
            DATA  = 5,
            SET   = 6
        };

    public:
        DTypeFlipFlopWithSR();
        ~DTypeFlipFlopWithSR() noexcept override = default;

    private:
        void computeOutputs() final;

    private:
        InternComponent m_invert_data;
    };
}

#endif /* !DTYPEFLIPFLOPWITHSR_HPP_ */
