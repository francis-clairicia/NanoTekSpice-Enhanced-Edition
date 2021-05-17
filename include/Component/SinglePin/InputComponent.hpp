/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "SinglePinComponent.hpp"

namespace nts
{
    class InputComponent: public SinglePinComponent
    {
    public:
        enum PinName
        {
            OUTPUT = 1
        };

    public:
        explicit InputComponent(ComponentType type = ComponentType::Input) noexcept;
        ~InputComponent() noexcept override = default;

        void simulate(std::size_t tick) override;

        virtual void setValue(Tristate value) noexcept;

    protected:
        std::size_t   m_actual_tick;
        Tristate m_value_for_next_tick;
    };
}

#endif /* !INPUTCOMPONENT_HPP_ */
