/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"
#include "BadPinException.hpp"

nts::OutputComponent::OutputComponent() noexcept:
    SinglePinComponent("output")
{
}

void nts::OutputComponent::simulate(std::size_t tick __attribute__((unused)))
{
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::BadPinException(m_type, pin);
    m_value = (m_link.component) ? m_link.component->compute(m_link.pin) : nts::UNDEFINED;
    return m_value;
}
