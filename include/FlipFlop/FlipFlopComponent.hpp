/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** FlipFlopComponent
*/

#ifndef FLIPFLOPCOMPONENT_HPP_
#define FLIPFLOPCOMPONENT_HPP_

#include "AComponent.hpp"
#include "GateNOT.hpp"

namespace nts
{
    class FlipFlopComponent: public nts::AComponent {
        public:
            FlipFlopComponent() noexcept;
            ~FlipFlopComponent();

            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;
            void dump() const override;

            nts::Tristate operationQ(nts::Tristate cl, nts::Tristate d, nts::Tristate r, nts::Tristate s);
            nts::Tristate operationNotQ(nts::Tristate cl, nts::Tristate d, nts::Tristate r, nts::Tristate s);
    };
}

#endif /* !FLIPFLOPCOMPONENT_HPP_ */
