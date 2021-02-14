/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#ifndef ONEINPUTGATE_HPP_
#define ONEINPUTGATE_HPP_

#include "ACalculationComponent.hpp"

namespace nts
{
    class OneInputGate: public nts::ACalculationComponent {
        public:
            OneInputGate(const std::string &type) noexcept;
            ~OneInputGate() override;

            void simulate(std::size_t tick) override;

            virtual nts::Tristate operation(nts::Tristate a) const = 0;
        
        protected:
            nts::Tristate computeOutput(std::size_t pin) final;
    };
}

#endif /* !ONEINPUTGATE_HPP_ */
