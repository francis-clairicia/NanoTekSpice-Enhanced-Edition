/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateOR
*/

#ifndef GATEOR_HPP_
#define GATEOR_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateOR: public nts::GateTwoInputs {
        public:
            GateOR() noexcept;
            nts::Tristate operation(const nts::Tristate &a, const nts::Tristate &b) const final;
    };
}

#endif /* !GATEOR_HPP_ */
