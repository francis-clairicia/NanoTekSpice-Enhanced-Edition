/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ConstComponent
*/

#ifndef CONSTCOMPONENT_HPP_
#define CONSTCOMPONENT_HPP_

#include "InputComponent.hpp"
#include "ConstComponentException.hpp"

namespace nts
{
    template<nts::ComponentType Type, nts::Tristate Value>
    class ConstComponent: public nts::InputComponent {
        public:
            ConstComponent(): InputComponent()
            {
                if (Value == nts::UNDEFINED)
                    throw nts::ConstComponentException("the constant value of a ConstComponent should not be 'undefined'");
                m_value = Value;
                m_type = Type;
            }

            void setValue(nts::Tristate value __attribute__((unused))) final
            {
                throw nts::ConstComponentException("Cannot set value to a \"" + COMPONENT_TYPE_AS_STRING.at(m_type) + "\" component");
            }
    };

    using TrueComponent = ConstComponent<nts::TrueComponentType, nts::TRUE>;
    using FalseComponent = ConstComponent<nts::FalseComponentType, nts::FALSE>;
}

#endif /* !CONSTCOMPONENT_HPP_ */
