/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4017
*/

#ifndef COMPONENT4017_HPP_
#define COMPONENT4017_HPP_

#include "ACalculationComponent.hpp"

namespace nts
{
    class Component4017 final: public ACalculationComponent
    {
    public:
        enum PinName
        {
            Q5    = 1,
            Q1    = 2,
            Q0    = 3,
            Q2    = 4,
            Q6    = 5,
            Q7    = 6,
            Q3    = 7,
            Q8    = 9,
            Q4    = 10,
            Q9    = 11,
            Q5_9  = 12,
            CP1   = 13,
            CP0   = 14,
            MR    = 15
        };

    public:
        Component4017();
        ~Component4017() noexcept override = default;

    private:
        void computeOutputs() final;

    private:
        InternComponent m_invert_cp1;
        InternComponent m_and_gate_clock;
        std::size_t                 m_shift;
    };
}

#endif /* !COMPONENT4017_HPP_ */
