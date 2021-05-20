/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

namespace nts
{
    OutputComponent::OutputComponent(ComponentType type) noexcept:
        SinglePinComponent{type, Pin::INPUT}
    {
    }

    void OutputComponent::simulate(std::size_t tick)
    {
        m_value = m_pin.computeExternalLinks(tick);
    }

    Tristate OutputComponent::computeOutput()
    {
        return FALSE;
    }
} // namespace nts
