/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ToggleComponent
*/

#include "ToggleComponent.hpp"
#include "ResourcesManager.hpp"

namespace
{
    sf::IntRect RED_SWITCH{0, 21, 265, 130};
    sf::IntRect GREEN_SWITCH{0, 229, 265, 130};
} // namespace


namespace nts
{
    ToggleComponent::ToggleComponent():
        m_component{std::make_unique<InputComponent>()},
        m_intern_value{nts::FALSE},
        m_sprite{ResourcesManager::loadImage(SWITCH_IMG.data())}
    {
        m_text.setFont(ResourcesManager::loadFont(FONT_FILE.data()));
        m_text.setCharacterSize(25);
        m_component->setValue(m_intern_value);
        m_sprite.setScale({0.5f, 0.5f});
        update();
        m_text.setFillColor(sf::Color::White);
        m_box.setFillColor(sf::Color::Transparent);
        m_box.setOutlineThickness(2);
        m_box.setOutlineColor(sf::Color::Transparent);
    }

    void ToggleComponent::update() noexcept
    {
        if (m_intern_value == nts::TRUE) {
            m_sprite.setTextureRect(GREEN_SWITCH);
        } else {
            m_sprite.setTextureRect(RED_SWITCH);
        }

        m_text.setString(getName());

        sf::FloatRect sprite_bounds_global = m_sprite.getGlobalBounds();
        sf::FloatRect sprite_bounds = m_sprite.getLocalBounds();
        sf::FloatRect text_bounds_global = m_text.getGlobalBounds();
        sf::FloatRect text_bounds = m_text.getGlobalBounds();

        m_box.setSize({
            std::max(sprite_bounds_global.width, text_bounds_global.width) * 1.1f,
            sprite_bounds_global.height + text_bounds_global.height * 2.f
        });

        appyTransformations(m_box);

        sf::FloatRect bounds = getGlobalBounds();

        m_sprite.setOrigin({sprite_bounds.width / 2, 0});
        m_sprite.setPosition({bounds.left + bounds.width / 2, bounds.top});

        m_text.setOrigin({text_bounds.width / 2, text_bounds.height});
        m_text.setPosition({bounds.left + bounds.width / 2, bounds.top + bounds.height * 0.9f});

        if (isHighlighted()) {
            m_box.setOutlineColor(sf::Color::Yellow);
        } else {
            m_box.setOutlineColor(sf::Color::Transparent);
        }
    }

    sf::FloatRect ToggleComponent::getLocalBounds() const
    {
        return m_box.getLocalBounds();
    }

    IComponent *ToggleComponent::getInternalComponent() const noexcept
    {
        return m_component.get();
    }

    void ToggleComponent::mouseButtonClicked()
    {
        m_intern_value = static_cast<nts::Tristate>(!m_intern_value);
        m_component->setValue(m_intern_value);
    }

    void ToggleComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_sprite, states);
        target.draw(m_text, states);
        target.draw(m_box, states);
    }
} // namespace nts


