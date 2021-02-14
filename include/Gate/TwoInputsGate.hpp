/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** TwoInputsGate
*/

#ifndef TWOINPUTSGATE_HPP_
#define TWOINPUTSGATE_HPP_

#include "ACalculationComponent.hpp"

namespace nts
{
    class TwoInputsGate: public nts::ACalculationComponent {
        public:
            TwoInputsGate(const std::string &type) noexcept;
            ~TwoInputsGate() override;

            void simulate(std::size_t tick) override;

            virtual nts::Tristate operation(nts::Tristate a, nts::Tristate b) const = 0;
        
        protected:
            nts::Tristate computeOutput(std::size_t pin) final;
    };
}

#endif /* !TWOINPUTSGATE_HPP_ */
