/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** TwoBitsSubComponent
*/

#ifndef TWOBITSSUBCOMPONENT_HPP_
#define TWOBITSSUBCOMPONENT_HPP_

#include "BoxComponent.hpp"

namespace nts
{
    class TwoBitsSubComponent final: public BoxComponent
    {
    public:
        enum PinName
        {
            Xi   = 1,
            Yi   = 2,
            Bi   = 3,
            Bo   = 4,
            Diff = 5
        };

    public:
        TwoBitsSubComponent();
        ~TwoBitsSubComponent() noexcept override = default;

    private:
        void dumpInternalComponents() const noexcept final;

    private:
        InternComponent m_xor1;
        InternComponent m_xor2;
        InternComponent m_not1;
        InternComponent m_not2;
        InternComponent m_and1;
        InternComponent m_and2;
        InternComponent m_or;
    };
}

#endif /* !TWOBITSSUBCOMPONENT_HPP_ */
