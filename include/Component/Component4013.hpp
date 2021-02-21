/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4013
*/

#ifndef COMPONENT4013_HPP_
#define COMPONENT4013_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Component4013: public nts::AComponent {
        public:
            enum Pin
            {
                Q1     = 1,
                Q1n    = 2,
                CLOCK1 = 3,
                RESET1 = 4,
                DATA1  = 5,
                SET1   = 6,
                SET2   = 8,
                DATA2  = 9,
                RESET2 = 10,
                CLOCK2 = 11,
                Q2n    = 12,
                Q2     = 13,
            };

        public:
            Component4013() noexcept;
            ~Component4013() noexcept;

            void simulate(std::size_t tick) final;

        protected:
            void dumpInternalComponents() const final;

        private:
            internComponent_t m_components;
    };
}

#endif /* !COMPONENT4013_HPP_ */
