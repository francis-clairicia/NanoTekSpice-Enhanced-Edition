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
    template<nts::ComponentType Type, nts::Tristate Value>
    class ConstComponent: public nts::SinglePinComponent {
        public:
            enum PinName
            {
                OUTPUT = 1
            };

        public:
            ConstComponent(): SinglePinComponent(Type, nts::Pin::OUTPUT)
            {
                static_assert(Value != nts::UNDEFINED, "the constant value of a ConstComponent should not be 'undefined'");
                m_value = Value;
            }

            void simulate(std::size_t tick __attribute__((unused))) final
            {
            }

        protected:
            nts::Tristate computeOutput() final
            {
                return SinglePinComponent::computeOutput();
            }
    };

    using TrueComponent = ConstComponent<nts::ComponentType::True, nts::TRUE>;
    using FalseComponent = ConstComponent<nts::ComponentType::False, nts::FALSE>;
}

#endif /* !CONSTCOMPONENT_HPP_ */
