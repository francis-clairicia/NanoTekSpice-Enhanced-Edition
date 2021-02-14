/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SumComponent
*/

#ifndef SUMCOMPONENT_HPP_
#define SUMCOMPONENT_HPP_

#include "ACalculationComponent.hpp"

namespace nts
{
    class SumComponent: public nts::ACalculationComponent {
        public:
            SumComponent() noexcept;
            ~SumComponent();

            void simulate(std::size_t tick) final;

            nts::Tristate operationCo(nts::Tristate a, nts::Tristate b, nts::Tristate c);
            nts::Tristate operationS(nts::Tristate a, nts::Tristate b, nts::Tristate c);

        protected:
            nts::Tristate computeOutput(std::size_t pin) final;
    };
}

#endif /* !SUMCOMPONENT_HPP_ */
