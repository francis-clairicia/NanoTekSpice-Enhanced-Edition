/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4008
*/

#ifndef COMPONENT4008_HPP_
#define COMPONENT4008_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Component4008: public nts::AComponent {
        public:
            Component4008() noexcept;
            ~Component4008() noexcept;

            void simulate(std::size_t tick) final;

        protected:
            void dumpInternalComponents() const final;

        private:
            intern_component_t m_components;
    };
}

#endif /* !COMPONENT4008_HPP_ */
