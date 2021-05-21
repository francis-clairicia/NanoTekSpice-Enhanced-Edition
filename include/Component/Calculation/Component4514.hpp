/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4514
*/

#ifndef COMPONENT4514_HPP_
#define COMPONENT4514_HPP_

#include "BoxComponent.hpp"
#include "ACalculationComponent.hpp"

namespace nts
{
    class Component4514 final: public ACalculationComponent
    {
    public:
        enum PinName
        {
            STROBE  = 1,
            IN_A    = 2,
            IN_B    = 3,
            OUT_S7  = 4,
            OUT_S6  = 5,
            OUT_S5  = 6,
            OUT_S4  = 7,
            OUT_S3  = 8,
            OUT_S1  = 9,
            OUT_S2  = 10,
            OUT_S0  = 11,
            OUT_S13 = 13,
            OUT_S12 = 14,
            OUT_S15 = 15,
            OUT_S14 = 16,
            OUT_S9  = 17,
            OUT_S8  = 18,
            OUT_S11 = 19,
            OUT_S10 = 20,
            IN_C    = 21,
            IN_D    = 22,
            INHIBIT = 23,
        };

    public:
        Component4514();
        ~Component4514() noexcept override = default;

    private:
        void computeOutputs() final;

    private:
        InternComponent m_latch;

    private:
        class Latch final: public ACalculationComponent
        {
        public:
            enum PinName
            {
                INPUT_A      = 1,
                INPUT_B      = 2,
                INPUT_C      = 3,
                INPUT_D      = 4,
                INPUT_STROBE = 5,
                OUTPUT_A     = 6,
                OUTPUT_B     = 7,
                OUTPUT_C     = 8,
                OUTPUT_D     = 9,
            };

        public:
            Latch() noexcept;
            ~Latch() noexcept override = default;

        private:
            void computeOutputs() final;
        };
    };
}

#endif /* !COMPONENT4514_HPP_ */
