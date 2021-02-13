/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OutputComponent
*/

#include <iostream>
#include "OutputComponent.hpp"
#include "Exception.hpp"

nts::OutputComponent::OutputComponent() noexcept:
    IOComponent("output")
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::BadPinException(m_type, pin);
    m_value = (m_link) ? m_link->compute(m_link_pin) : nts::UNDEFINED;
    return m_value;
}
