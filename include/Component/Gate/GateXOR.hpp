/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateXOR
*/

#ifndef GATEXOR_HPP_
#define GATEXOR_HPP_

#include "GateTwoInputs.hpp"

namespace nts
{
    class GateXOR final: public GateTwoInputs
    {
    public:
        GateXOR() noexcept;
        ~GateXOR() noexcept override = default;

        Tristate operation(Tristate a, Tristate b) const noexcept final;
    };
}

#endif /* !GATEXOR_HPP_ */
