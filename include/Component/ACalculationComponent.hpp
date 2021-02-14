/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ACalculationComponent
*/

#ifndef ACALCULATIONCOMPONENT_HPP_
#define ACALCULATIONCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class ACalculationComponent: public nts::AComponent {
        public:
            ACalculationComponent(const std::string &type, std::size_t nb_pins, const pin_list_t &input_pins, const pin_list_t &output_pins) noexcept;

            nts::Tristate compute(std::size_t pin) final;
            void dump() const override;

        protected:
            virtual nts::Tristate computeOutput(std::size_t pin) = 0;
    };
}

#endif /* !ACALCULATIONCOMPONENT_HPP_ */
