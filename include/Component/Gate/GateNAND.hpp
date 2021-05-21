/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateNAND
*/

#ifndef GATENAND_HPP_
#define GATENAND_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateNAND final: public GateTwoInputs
    {
    public:
        GateNAND() noexcept;
        ~GateNAND() noexcept override = default;

        Tristate operation(Tristate a, Tristate b) const noexcept final;
    };
}

#endif /* !GATENAND_HPP_ */
