/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalInputComponent
*/

#include <iostream>
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
        std::cout << "Clicked" << '\n';
    }
} // namespace nts


