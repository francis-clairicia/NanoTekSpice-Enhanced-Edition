/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateAND
*/

#ifndef GATEAND_HPP_
#define GATEAND_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateAND: public nts::GateTwoInputs {
        public:
            GateAND() noexcept;
            nts::Tristate operation(const nts::Tristate &a, const nts::Tristate &b) const final;
    };
}

#endif /* !GATEAND_HPP_ */
