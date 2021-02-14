/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** TwoInputsGate
*/

#ifndef TWOINPUTSGATE_HPP_
#define TWOINPUTSGATE_HPP_

#include "AComponent.hpp"

namespace nts
{
    class TwoInputsGate: public nts::AComponent {
        public:
            TwoInputsGate(const std::string &type) noexcept;
            ~TwoInputsGate() override;

            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) final;
            void dump() const override;
            virtual nts::Tristate operation(nts::Tristate a, nts::Tristate b) const = 0;
    };
}

#endif /* !TWOINPUTSGATE_HPP_ */
