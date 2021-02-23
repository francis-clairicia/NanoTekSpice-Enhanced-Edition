/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** TwoInputsGate
*/

#ifndef TWOINPUTSGATE_HPP_
#define TWOINPUTSGATE_HPP_

#include "AGate.hpp"

namespace nts
{
    class TwoInputsGate: public nts::AGate {
        public:
            enum Pin
            {
                INPUT1 = 1,
                INPUT2 = 2,
                OUTPUT = 3
            };

        public:
            TwoInputsGate(nts::ComponentType type) noexcept;
            ~TwoInputsGate() override;

            virtual nts::Tristate operation(nts::Tristate a, nts::Tristate b) const = 0;
        
        protected:
            nts::Tristate computeOutput() final;
    };
}

#endif /* !TWOINPUTSGATE_HPP_ */
