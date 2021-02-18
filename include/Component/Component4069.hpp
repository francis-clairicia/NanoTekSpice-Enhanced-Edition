/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4069
*/

#ifndef COMPONENT4069_HPP_
#define COMPONENT4069_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Component4069: public nts::AComponent {
        public:
            Component4069() noexcept;
            ~Component4069() noexcept;

            void simulate(std::size_t tick) final;
    };
}

#endif /* !COMPONENT4069_HPP_ */
