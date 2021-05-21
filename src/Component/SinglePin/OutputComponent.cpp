/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
