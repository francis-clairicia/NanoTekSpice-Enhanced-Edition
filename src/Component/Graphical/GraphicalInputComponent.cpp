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
        m_text{TRISTATE_TO_STR.at(m_component->getValue()).data(), ResourcesManager::loadFont(FONT_FILE.data()), 25}
    {
        m_box.setFillColor(sf::Color::Black);
        m_text.setFillColor(sf::Color::White);
    }

    void GraphicalInputComponent::update(const std::string &component_name) noexcept
    {
        m_text.setString(component_name + "\nValue: " + TRISTATE_TO_STR.at(m_component->getValue()).data());

        sf::FloatRect text_bounds = m_text.getLocalBounds();

        m_text.setOrigin({text_bounds.width / 2, text_bounds.height / 1.5f});
        m_box.setSize({text_bounds.width * 1.20f, text_bounds.height * 1.70f});
        m_box.setOrigin(getOrigin());
        m_box.setPosition(getPosition());

        if (isClicked()) {
            m_box.setFillColor({127, 127, 127});
        } else {
            m_box.setFillColor(sf::Color::Black);
        }

        sf::FloatRect box_bounds = m_box.getGlobalBounds();

        m_text.setPosition({box_bounds.left + box_bounds.width / 2, box_bounds.top + box_bounds.height / 2});
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


