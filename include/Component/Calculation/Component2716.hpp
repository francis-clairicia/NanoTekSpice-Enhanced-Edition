/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component2716
*/

#ifndef COMPONENT2716_HPP_
#define COMPONENT2716_HPP_

#include "ACalculationComponent.hpp"
#include "Memory.hpp"

namespace nts
{
    class Component2716 final: public ACalculationComponent
    {
    public:
        enum PinName
        {
            A7             = 1,
            A6             = 2,
            A5             = 3,
            A4             = 4,
            A3             = 5,
            A2             = 6,
            A1             = 7,
            A0             = 8,
            Q0             = 9,
            Q1             = 10,
            Q2             = 11,
            Q3             = 13,
            Q4             = 14,
            Q5             = 15,
            Q6             = 16,
            Q7             = 17,
            CHIP_ENABLED   = 18,
            A10            = 19,
            OUTPUT_ENABLED = 20,
            A9             = 22,
            A8             = 23
        };

    public:
        Component2716();
        ~Component2716() noexcept override = default;

    private:
        void computeOutputs() final;

    private:
        InternComponent m_invert_oe;
        InternComponent m_invert_ce_pgm;
        Memory<2048UL>  m_memory;
    };
}

#endif /* !COMPONENT2716_HPP_ */
