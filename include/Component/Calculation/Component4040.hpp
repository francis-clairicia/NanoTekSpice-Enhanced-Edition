/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4040
*/

#ifndef COMPONENT4040_HPP_
#define COMPONENT4040_HPP_

#include "ACalculationComponent.hpp"

namespace nts
{
    class Component4040 final: public ACalculationComponent
    {
    public:
        enum PinName
        {
            Q12   = 1,
            Q6    = 2,
            Q5    = 3,
            Q7    = 4,
            Q4    = 5,
            Q3    = 6,
            Q2    = 7,
            Q1    = 9,
            CLOCK = 10,
            RESET = 11,
            Q9    = 12,
            Q8    = 13,
            Q10   = 14,
            Q11   = 15
        };

    public:
        Component4040();
        ~Component4040() noexcept override = default;

    private:
        void computeOutputs() final;

    private:
        InternComponent m_invert_clock;
        std::size_t                 m_counter;
    };
}

#endif /* !COMPONENT4040_HPP_ */
