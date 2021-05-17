/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ConstComponent
*/

#ifndef CONSTCOMPONENT_HPP_
#define CONSTCOMPONENT_HPP_

#include "SinglePinComponent.hpp"

namespace nts
{
    template<ComponentType Type, Tristate Value>
    class ConstComponent final: public SinglePinComponent
    {
    public:
        enum PinName
        {
            OUTPUT = 1
        };

    public:
        ConstComponent(): SinglePinComponent{Type, Pin::OUTPUT}
        {
            static_assert(Value != UNDEFINED, "the constant value of a ConstComponent should not be 'undefined'");
            m_value = Value;
        }
        ~ConstComponent() noexcept override = default;

        void simulate(std::size_t tick __attribute__((unused))) final
        {
        }
    };

    using TrueComponent = ConstComponent<ComponentType::True, TRUE>;
    using FalseComponent = ConstComponent<ComponentType::False, FALSE>;
}

#endif /* !CONSTCOMPONENT_HPP_ */
