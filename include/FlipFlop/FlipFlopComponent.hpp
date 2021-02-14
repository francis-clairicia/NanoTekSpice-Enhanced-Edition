/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** FlipFlopComponent
*/

#ifndef FLIPFLOPCOMPONENT_HPP_
#define FLIPFLOPCOMPONENT_HPP_

#include "ACalculationComponent.hpp"

namespace nts
{
    class FlipFlopComponent: public nts::ACalculationComponent {
        public:
            FlipFlopComponent() noexcept;
            ~FlipFlopComponent();

            void simulate(std::size_t tick) final;

            nts::Tristate operationQ(nts::Tristate cl, nts::Tristate d, nts::Tristate r, nts::Tristate s);
            nts::Tristate operationNotQ(nts::Tristate cl, nts::Tristate d, nts::Tristate r, nts::Tristate s);
        
        protected:
            nts::Tristate computeOutput(std::size_t pin) final;
    };
}

#endif /* !FLIPFLOPCOMPONENT_HPP_ */
