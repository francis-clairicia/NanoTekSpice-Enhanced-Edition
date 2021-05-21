/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GateOneInput
*/

#ifndef GATEONEINPUT_HPP_
#define GATEONEINPUT_HPP_

#include "AGate.hpp"

namespace nts
{
    class GateOneInput: public AGate
    {
    public:
        enum PinName
        {
            INPUT  = 1,
            OUTPUT = 2,
        };

    public:
        explicit GateOneInput(ComponentType type) noexcept;
        ~GateOneInput() noexcept override = default;

        virtual Tristate operation(Tristate a) const noexcept = 0;

    private:
        Tristate computeOutput() final;
    };
}

#endif /* !GATEONEINPUT_HPP_ */
