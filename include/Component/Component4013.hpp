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
            Component4013() noexcept;
            ~Component4013() noexcept;

            void simulate(std::size_t tick) final;

        protected:
            void dumpInternalComponents() const final;

        protected:
            intern_component_t m_components;
    };
}

#endif /* !COMPONENT4013_HPP_ */
