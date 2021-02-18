/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4011
*/

#ifndef COMPONENT4011_HPP_
#define COMPONENT4011_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Component4011: public nts::AComponent {
        public:
            Component4011() noexcept;
            ~Component4011() noexcept;

            void simulate(std::size_t tick) final;

        protected:
            void dumpInternalComponents() const final;

        private:
            internComponent_t m_components;
    };
}

#endif /* !COMPONENT4011_HPP_ */
