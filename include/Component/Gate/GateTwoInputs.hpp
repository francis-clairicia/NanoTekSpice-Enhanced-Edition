/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
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
        void computeOutput() final;
    };
}

#endif /* !GATETWOINPUTS_HPP_ */
