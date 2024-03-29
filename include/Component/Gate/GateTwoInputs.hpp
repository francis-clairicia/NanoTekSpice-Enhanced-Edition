/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateTwoInputs
*/

#ifndef GATETWOINPUTS_HPP_
#define GATETWOINPUTS_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateTwoInputs: public AGate
    {
    public:
        enum PinName
        {
            INPUT1 = 1,
            INPUT2 = 2,
            OUTPUT = 3
        };

    public:
        explicit GateTwoInputs(ComponentType type) noexcept;
        ~GateTwoInputs() noexcept override = default;

        virtual Tristate operation(Tristate a, Tristate b) const noexcept = 0;

    private:
        Tristate computeOutput() final;
    };
}

#endif /* !GATETWOINPUTS_HPP_ */
