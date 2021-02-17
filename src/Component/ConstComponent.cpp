/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ConstComponent
*/

#include "ConstComponent.hpp"
#include "ConstComponentException.hpp"

nts::ConstComponent::ConstComponent(const std::string &type, nts::Tristate value): InputComponent()
{
    if (value == nts::UNDEFINED)
        throw nts::ConstComponentException("the constant value of a ConstComponent should not be 'undefined'");
    m_value = value;
    m_type = type;
}

void nts::ConstComponent::setValue(const std::string &value __attribute__((unused)))
{
    throw nts::ConstComponentException("Cannot set value to ConstComponent");
}
