/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Component4512
*/

#ifndef COMPONENT4512_HPP_
#define COMPONENT4512_HPP_

#include "ACalculationComponent.hpp"

namespace nts
{
    class Component4512: public nts::ACalculationComponent {
        public:
            enum PinName
            {
                X0       = 1,
                X1       = 2,
                X2       = 3,
                X3       = 4,
                X4       = 5,
                X5       = 6,
                X6       = 7,
                X7       = 9,
                INHIBIT  = 10,
                INPUT_A  = 11,
                INPUT_B  = 12,
                INPUT_C  = 13,
                OUTPUT_Z = 14,
                INPUT_OE = 15
            };

        public:
            Component4512() noexcept;
            ~Component4512() noexcept = default;

        protected:
            void computeOutputs() final;

        private:
            std::unique_ptr<nts::IComponent> m_invert_oe;
    };
}

#endif /* !COMPONENT4512_HPP_ */
