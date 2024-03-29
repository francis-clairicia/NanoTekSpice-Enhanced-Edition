/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4008
*/

#ifndef COMPONENT4008_HPP_
#define COMPONENT4008_HPP_

#include "BoxComponent.hpp"

namespace nts
{
    class Component4008 final: public BoxComponent
    {
    public:
        enum PinName
        {
            A4   = 1,
            B3   = 2,
            A3   = 3,
            B2   = 4,
            A2   = 5,
            B1   = 6,
            A1   = 7,
            Cin  = 9,
            S1   = 10,
            S2   = 11,
            S3   = 12,
            S4   = 13,
            Cout = 14,
            B4   = 15
        };

    public:
        Component4008();
        ~Component4008() noexcept override = default;

    private:
        void dumpInternalComponents() const noexcept final;

    private:
        InternComponentList m_components;
    };
}

#endif /* !COMPONENT4008_HPP_ */
