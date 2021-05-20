/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SumComponent
*/

#ifndef SUMCOMPONENT_HPP_
#define SUMCOMPONENT_HPP_

#include "BoxComponent.hpp"

namespace nts
{
    class SumComponent final: public BoxComponent
    {
    public:
        enum PinName
        {
            Ai = 1,
            Bi = 2,
            Ci = 3,
            Co = 4,
            Si = 5
        };

    public:
        SumComponent() noexcept;
        ~SumComponent() noexcept override = default;

    private:
        void dumpInternalComponents() const noexcept final;

    private:
        InternComponent m_xor1;
        InternComponent m_xor2;
        InternComponent m_and1;
        InternComponent m_and2;
        InternComponent m_or;
    };
}

#endif /* !SUMCOMPONENT_HPP_ */
