/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** SubComponent
*/

#ifndef SUBCOMPONENT_HPP_
#define SUBCOMPONENT_HPP_

#include "BoxComponent.hpp"

namespace nts
{
    class SubComponent final: public BoxComponent
    {
    public:
        enum PinName
        {
            X4   = 1,
            Y3   = 2,
            X3   = 3,
            Y2   = 4,
            X2   = 5,
            Y1   = 6,
            X1   = 7,
            Bin  = 9,
            S1   = 10,
            S2   = 11,
            S3   = 12,
            S4   = 13,
            Bout = 14,
            Y4   = 15
        };

    public:
        SubComponent();
        ~SubComponent() noexcept override = default;

    private:
        void dumpInternalComponents() const noexcept final;

    private:
        InternComponentList m_components;
    };
} // namespace nts


#endif /* !SUBCOMPONENT_HPP_ */
