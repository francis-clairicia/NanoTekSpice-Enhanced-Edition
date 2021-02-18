/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4030
*/

#ifndef COMPONENT4030_HPP_
#define COMPONENT4030_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Component4030: public nts::AComponent {
        public:
            Component4030() noexcept;
            ~Component4030() noexcept;

            void simulate(std::size_t tick) final;
    };
}

#endif /* !COMPONENT4030_HPP_ */
