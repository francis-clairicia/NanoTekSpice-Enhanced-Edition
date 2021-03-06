/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateOneInput
*/

#ifndef GATEONEINPUT_HPP_
#define GATEONEINPUT_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateOneInput: public nts::AGate {
        public:
            enum PinName
            {
                INPUT  = 1,
                OUTPUT = 2,
            };

        public:
            GateOneInput(nts::ComponentType type) noexcept;
            ~GateOneInput() noexcept;

            virtual nts::Tristate operation(const nts::Tristate &a) const noexcept = 0;
        
        protected:
            nts::Tristate computeOutput() final;
    };
}

#endif /* !GATEONEINPUT_HPP_ */
