/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include "SinglePinComponent.hpp"

namespace nts
{
    class OutputComponent: public nts::SinglePinComponent {
        public:
            enum PinName
            {
                INPUT = 1
            };

        public:
            OutputComponent(nts::ComponentType type = ComponentType::Output) noexcept;

            void simulate(std::size_t tick) override;
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
