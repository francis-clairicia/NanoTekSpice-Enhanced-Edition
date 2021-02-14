/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#ifndef ONEINPUTGATE_HPP_
#define ONEINPUTGATE_HPP_

#include "AComponent.hpp"

namespace nts
{
    class OneInputGate: public nts::AComponent {
        public:
            OneInputGate(const std::string &type) noexcept;
            ~OneInputGate() override;

            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) final;
            void dump() const override;
            virtual nts::Tristate operation(nts::Tristate a) const = 0;
    };
}

#endif /* !ONEINPUTGATE_HPP_ */
