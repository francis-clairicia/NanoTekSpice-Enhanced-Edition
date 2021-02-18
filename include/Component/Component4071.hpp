/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4071
*/

#ifndef COMPONENT4071_HPP_
#define COMPONENT4071_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Component4071: public nts::AComponent {
        public:
            Component4071() noexcept;
            ~Component4071() noexcept;

            void simulate(std::size_t tick) final;

        protected:
            intern_component_t m_components;
    };
}

#endif /* !COMPONENT4071_HPP_ */
