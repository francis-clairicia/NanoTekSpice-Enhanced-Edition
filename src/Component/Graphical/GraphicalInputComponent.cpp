/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalInputComponent
*/

#include "GraphicalInputComponent.hpp"
#include "ResourcesManager.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace
{
    const std::unordered_map<nts::Tristate, std::string_view> TRISTATE_TO_STR{
        {nts::FALSE,     "0"},
        {nts::TRUE,      "1"},
        {nts::UNDEFINED, "U"}
    };

    constexpr std::string_view FONT_FILE{"./assets/font/input.ttf"};
} // namespace


namespace nts
{
    GraphicalInputComponent::GraphicalInputComponent()
        // m_text{TRISTATE_TO_STR.at(getValue()).data(), ResourcesManager::loadFont(FONT_FILE.data())}
    {
    }

    sf::FloatRect GraphicalInputComponent::getLocalBounds() const
    {
        return m_box.getLocalBounds();
    }

    void GraphicalInputComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_box, states);
        target.draw(m_text, states);
    }
} // namespace nts


