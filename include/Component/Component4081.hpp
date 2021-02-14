/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Component4081: public nts::AComponent {
        public:
            Component4081() noexcept;
            ~Component4081();

            void simulate(std::size_t tick) final;
    };
}

#endif /* !COMPONENT4081_HPP_ */
