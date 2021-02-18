/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** FlipFlopComponent
*/

#ifndef FLIPFLOPCOMPONENT_HPP_
#define FLIPFLOPCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class FlipFlopComponent: public nts::AComponent {
        public:
            FlipFlopComponent() noexcept;
            ~FlipFlopComponent();

            void simulate(std::size_t tick) final;
    };
}

#endif /* !FLIPFLOPCOMPONENT_HPP_ */
