/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4008
*/

#ifndef COMPONENT4008_HPP_
#define COMPONENT4008_HPP_

#include "BoxComponent.hpp"

namespace nts
{
    class Component4008: public nts::BoxComponent {
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
            Component4008() noexcept;
            ~Component4008() noexcept;

        protected:
            void dumpInternalComponents() const noexcept final;

        private:
            nts::internComponent_t m_components;
    };
}

#endif /* !COMPONENT4008_HPP_ */
