/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SumComponent
*/

#ifndef SUMCOMPONENT_HPP_
#define SUMCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class SumComponent: public nts::AComponent {
        public:
            SumComponent() noexcept;
            ~SumComponent();

            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;
            void dump() const override;

            nts::Tristate operation_Co(nts::Tristate a, nts::Tristate b, nts::Tristate c);
            nts::Tristate operation_S(nts::Tristate a, nts::Tristate b, nts::Tristate c);

        private:
    };
}

#endif /* !SUMCOMPONENT_HPP_ */
