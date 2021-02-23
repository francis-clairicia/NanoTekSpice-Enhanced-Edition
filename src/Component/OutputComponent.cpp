/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"
#include "BadPinException.hpp"

nts::OutputComponent::OutputComponent() noexcept:
    SinglePinComponent(OutputComponentType)
{
}

void nts::OutputComponent::simulate(std::size_t tick)
{
    if (m_link.component) {
        m_link.component->simulate(tick);
        m_value = m_link.component->compute(m_link.pin);
    } else {
        m_value = nts::UNDEFINED;
    }
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != INPUT)
        throw nts::BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    return m_value;
}
