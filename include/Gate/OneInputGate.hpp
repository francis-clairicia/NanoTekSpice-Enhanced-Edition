/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#ifndef ONEINPUTGATE_HPP_
#define ONEINPUTGATE_HPP_

#include "AGate.hpp"

namespace nts
{
    class OneInputGate: public nts::AGate {
        public:
            enum Pin
            {
                INPUT  = 1,
                OUTPUT = 2,
            };

        public:
            OneInputGate(nts::ComponentType type) noexcept;
            ~OneInputGate() override;

            virtual nts::Tristate operation(nts::Tristate a) const = 0;
        
        protected:
            nts::Tristate computeOutput() final;
    };
}

#endif /* !ONEINPUTGATE_HPP_ */
