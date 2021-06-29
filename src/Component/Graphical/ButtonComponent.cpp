/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ButtonComponent
*/

#include "ButtonComponent.hpp"
#include "ResourcesManager.hpp"

namespace nts
{
    ButtonComponent::ButtonComponent():
        m_component{std::make_unique<InputComponent>()}
    {
        m_text.setFont(ResourcesManager::loadFont(FONT_FILE.data()));
        m_text.setCharacterSize(15);
        m_component->setValue(FALSE);
        m_button.setFillColor(sf::Color::Red);
        m_button.setOutlineColor(sf::Color::Transparent);
        m_button.setOutlineThickness(2);
    }

    void ButtonComponent::update() noexcept
    {
        m_component->setValue(static_cast<Tristate>(isClicked() && !isMoving()));

        if (m_component->getValue() == TRUE) {
            m_button.setFillColor(sf::Color::Green);
        } else {
            m_button.setFillColor(sf::Color::Red);
        }

        m_text.setString(getName());

        sf::FloatRect text_bounds_global = m_text.getGlobalBounds();
        sf::FloatRect text_bounds = m_text.getGlobalBounds();

        m_button.setRadius({text_bounds_global.width / 2});

        appyTransformations(m_button);

        sf::FloatRect bounds = getGlobalBounds();

        m_text.setOrigin({text_bounds.width / 2, text_bounds.height});
        m_text.setPosition({bounds.left + bounds.width / 2, bounds.top + bounds.height / 2});

        if (isHighlighted()) {
            m_button.setOutlineColor(sf::Color::Yellow);
        } else {
            m_button.setOutlineColor(sf::Color::Transparent);
        }
    }

    sf::FloatRect ButtonComponent::getLocalBounds() const
    {
        return m_button.getLocalBounds();
    }

    IComponent *ButtonComponent::getInternalComponent() const noexcept
    {
        return m_component.get();
    }

    void ButtonComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_button, states);
        target.draw(m_text, states);
    }
} // namespace nts


