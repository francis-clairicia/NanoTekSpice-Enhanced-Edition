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
        m_text{TRISTATE_TO_STR.at(m_component->getValue()).data(), ResourcesManager::loadFont(FONT_FILE.data()), 50}
    {
        m_box.setFillColor(sf::Color::Black);
        m_text.setFillColor(sf::Color::White);
    }

    void GraphicalInputComponent::update() noexcept
    {
        sf::FloatRect text_bounds = m_text.getLocalBounds();

        m_text.setOrigin({text_bounds.width / 2, text_bounds.height / 2});
        m_box.setSize({text_bounds.width + 20, text_bounds.height + 20});
        m_box.setOrigin(getOrigin());
        m_box.setPosition(getPosition());

        sf::FloatRect box_bounds = m_box.getGlobalBounds();

        m_text.setPosition({box_bounds.left + box_bounds.width / 2, box_bounds.top + box_bounds.height / 5});
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


