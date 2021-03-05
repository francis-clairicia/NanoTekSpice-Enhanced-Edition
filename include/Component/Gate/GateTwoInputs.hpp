/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTwoInputs
*/

#ifndef GATETWOINPUTS_HPP_
#define GATETWOINPUTS_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateTwoInputs: public nts::AGate {
        public:
            enum Pin
            {
                INPUT1 = 1,
                INPUT2 = 2,
                OUTPUT = 3
            };

        public:
            GateTwoInputs(nts::ComponentType type) noexcept;
            ~GateTwoInputs() override;

            virtual nts::Tristate operation(nts::Tristate a, nts::Tristate b) const = 0;
        
        protected:
            nts::Tristate computeOutput() final;
    };
}

#endif /* !GATETWOINPUTS_HPP_ */
