/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"

namespace nts
{
    ClockComponent::ClockComponent() noexcept:
        InputComponent{ComponentType::Clock},
        m_invert_value{true}
    {
    }

    void ClockComponent::simulate(std::size_t tick)
    {
        if (m_actual_tick != tick) {
            m_actual_tick = tick;
            if (m_invert_value && m_value != UNDEFINED)
                m_value = static_cast<Tristate>(!m_value);
            else
                m_value = m_value_for_next_tick;
            m_invert_value = true;
        }
    }

    void ClockComponent::setValue(Tristate value) noexcept
    {
        InputComponent::setValue(value);
        m_invert_value = false;
    }
} // namespace nts