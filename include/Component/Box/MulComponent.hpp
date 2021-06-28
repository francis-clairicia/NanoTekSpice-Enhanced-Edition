/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** MulComponent
*/

#ifndef MULCOMPONENT_HPP_
#define MULCOMPONENT_HPP_

#include "BoxComponent.hpp"

namespace nts
{
    class MulComponent final: public BoxComponent
    {
    public:
        enum PinName
        {
            A0 = 1,
            A1 = 2,
            A2 = 3,
            A3 = 4,
            B0 = 5,
            B1 = 6,
            B2 = 7,
            B3 = 8,
            S0 = 10,
            S1 = 11,
            S2 = 12,
            S3 = 13,
            S4 = 14,
            S5 = 15,
            S6 = 16,
            S7 = 17,
        };

    public:
        MulComponent();
        ~MulComponent() noexcept override = default;

    private:
        InternComponentList m_adder;
        InternComponentList m_and;
        InternComponent     m_zero;
    };
} // namespace nts

#endif /* !MULCOMPONENT_HPP_ */
