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
        m_sprite{ResourcesManager::loadImage(SWITCH_IMG.data()), RED_SWITCH}
    {
        setScale({0.5f, 0.5f});
    }

    void ToggleComponent::update() noexcept
    {
        if (m_intern_value == nts::TRUE) {
            m_sprite.setTextureRect(GREEN_SWITCH);
        } else {
            m_sprite.setTextureRect(RED_SWITCH);
        }

        m_sprite.setOrigin(getOrigin());
        m_sprite.setPosition(getPosition());
        m_sprite.setRotation(getRotation());
        m_sprite.setScale(getScale());
    }

    sf::FloatRect ToggleComponent::getLocalBounds() const
    {
        return m_sprite.getLocalBounds();
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
    }
} // namespace nts


