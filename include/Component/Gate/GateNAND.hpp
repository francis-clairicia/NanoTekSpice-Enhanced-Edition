/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateNAND
*/

#ifndef GATENAND_HPP_
#define GATENAND_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateNAND: public nts::GateTwoInputs {
        public:
            GateNAND() noexcept;
            nts::Tristate operation(const nts::Tristate &a, const nts::Tristate &b) const noexcept final;
    };
}

#endif /* !GATENAND_HPP_ */
