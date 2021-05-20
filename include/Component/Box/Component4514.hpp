/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Component4514
*/

#ifndef COMPONENT4514_HPP_
#define COMPONENT4514_HPP_

#include "BoxComponent.hpp"
#include "ACalculationComponent.hpp"

namespace nts
{
    class Component4514 final: public BoxComponent
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
        Component4514() noexcept;
        ~Component4514() noexcept override = default;

    private:
        InternComponent m_latch;
        InternComponent m_decoder;

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

        class Decoder final: public ACalculationComponent
        {
        public:
            enum PinName
            {
                INPUT_A       = 1,
                INPUT_B       = 2,
                INPUT_C       = 3,
                INPUT_D       = 4,
                OUTPUT_S0     = 5,
                OUTPUT_S1     = 6,
                OUTPUT_S2     = 7,
                OUTPUT_S3     = 8,
                OUTPUT_S4     = 9,
                OUTPUT_S5     = 10,
                OUTPUT_S6     = 11,
                OUTPUT_S7     = 12,
                OUTPUT_S8     = 13,
                OUTPUT_S9     = 14,
                OUTPUT_S10    = 15,
                OUTPUT_S11    = 16,
                OUTPUT_S12    = 17,
                OUTPUT_S13    = 18,
                OUTPUT_S14    = 19,
                OUTPUT_S15    = 20,
                INPUT_INHIBIT = 21,
            };

        public:
            Decoder() noexcept;
            ~Decoder() noexcept override = default;

        private:
            void computeOutputs() final;
        };
    };
}

#endif /* !COMPONENT4514_HPP_ */
