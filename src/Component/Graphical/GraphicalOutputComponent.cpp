/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalOutputComponent
*/

#include "GraphicalOutputComponent.hpp"

namespace nts
{
    GraphicalOutputComponent::GraphicalOutputComponent()
    {
        m_box.setFillColor(sf::Color::White);
        m_text.setFillColor(sf::Color::Black);
    }

    void GraphicalOutputComponent::update(const std::string &component_name) noexcept
    {
        GraphicalIOComponent<OutputComponent>::update(component_name);
        if (isClicked()) {
            m_box.setFillColor({127, 127, 127});
        } else {
            m_box.setFillColor(sf::Color::White);
        }
    }
} // namespace nts
