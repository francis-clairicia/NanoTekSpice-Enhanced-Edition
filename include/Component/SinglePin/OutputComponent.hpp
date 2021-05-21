/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include "SinglePinComponent.hpp"

namespace nts
{
    class OutputComponent: public SinglePinComponent
    {
    public:
        enum PinName
        {
            INPUT = 1
        };

    public:
        explicit OutputComponent(ComponentType type = ComponentType::Output) noexcept;
        ~OutputComponent() noexcept override = default;

        void simulate(std::size_t tick) override;

    protected:
        Tristate computeOutput() override;
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
