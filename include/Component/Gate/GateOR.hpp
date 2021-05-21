/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateOR
*/

#ifndef GATEOR_HPP_
#define GATEOR_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateOR final: public GateTwoInputs
    {
    public:
        GateOR() noexcept;
        ~GateOR() noexcept override = default;

        Tristate operation(Tristate a, Tristate b) const noexcept final;
    };
}

#endif /* !GATEOR_HPP_ */
