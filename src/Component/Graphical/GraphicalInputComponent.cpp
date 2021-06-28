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
} // namespace


namespace nts
{
    GraphicalInputComponent::GraphicalInputComponent():
        m_component{std::make_unique<InputComponent>()},
        m_text{TRISTATE_TO_STR.at(m_component->getValue()).data(), ResourcesManager::loadFont(FONT_FILE.data())}
    {
        sf::FloatRect text_bounds = m_text.getLocalBounds();

        m_text.setFillColor(sf::Color::White);
        m_box.setSize({text_bounds.width, text_bounds.height});
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

    IComponent *GraphicalInputComponent::getInternalComponent() const noexcept
    {
        return m_component.get();
    }
} // namespace nts


