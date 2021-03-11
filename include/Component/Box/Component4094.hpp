/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Component4094
*/

#ifndef COMPONENT4094_HPP_
#define COMPONENT4094_HPP_

#include "BoxComponent.hpp"
#include "ACalculationComponent.hpp"

namespace nts
{
    class Component4094: public nts::BoxComponent {
        public:
            enum PinName
            {
                STROBE = 1,
                DATA   = 2,
                CLOCK  = 3,
                Q1     = 4,
                Q2     = 5,
                Q3     = 6,
                Q4     = 7,
                QS     = 9,
                QSp    = 10,
                Q8     = 11,
                Q7     = 12,
                Q6     = 13,
                Q5     = 14,
                OE     = 15,
            };

        public:
            Component4094() noexcept;
            ~Component4094() noexcept = default;

        private:
            std::unique_ptr<IComponent> m_ground;
            std::unique_ptr<IComponent> m_invert_clock;
            std::unique_ptr<IComponent> m_shift_register;
            std::unique_ptr<IComponent> m_qs_prime_flipflop;
            nts::internComponent_t      m_output_transmissions;
            nts::internComponent_t      m_output_flipflops;

        private:
            class ShiftRegister: public nts::ACalculationComponent {
                public:
                    enum PinName
                    {
                        INPUT_DATA_Q1 = 1,
                        INPUT_CLOCK   = 2,
                        OUTPUT_Q1     = 3,
                        OUTPUT_Q2     = 4,
                        OUTPUT_Q3     = 5,
                        OUTPUT_Q4     = 6,
                        OUTPUT_Q5     = 7,
                        OUTPUT_Q6     = 8,
                        OUTPUT_Q7     = 9,
                        OUTPUT_Q8     = 10
                    };

                public:
                    ShiftRegister() noexcept;
                    ~ShiftRegister() noexcept;

                protected:
                    void computeOutputs(std::size_t tick) final;
            };
    };
}

#endif /* !COMPONENT4094_HPP_ */
