/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalInputComponent
*/

#include "GraphicalInputComponent.hpp"

namespace nts
{
    GraphicalInputComponent::GraphicalInputComponent()
    {
        m_box.setFillColor(sf::Color::Black);
        m_text.setFillColor(sf::Color::White);
    }

    void GraphicalInputComponent::update() noexcept
    {
        GraphicalIOComponent<InputComponent>::update();

        if (isClicked()) {
            m_box.setFillColor({127, 127, 127});
        } else {
            m_box.setFillColor(sf::Color::Black);
        }
    }

    void GraphicalInputComponent::mouseButtonClicked()
    {
        switch (m_component->getValue())
        {
        case UNDEFINED:
            m_component->setValue(FALSE);
            break;
        case FALSE:
            m_component->setValue(TRUE);
            break;
        case TRUE:
            m_component->setValue(UNDEFINED);
            break;
        default:
            break;
        }
    }
} // namespace nts


