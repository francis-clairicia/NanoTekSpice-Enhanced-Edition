/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4001
*/

#ifndef COMPONENT4001_HPP_
#define COMPONENT4001_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Component4001: public nts::AComponent {
        public:
            Component4001() noexcept;
            ~Component4001();

            void simulate(std::size_t tick) final;
    };
}

#endif /* !COMPONENT4001_HPP_ */
