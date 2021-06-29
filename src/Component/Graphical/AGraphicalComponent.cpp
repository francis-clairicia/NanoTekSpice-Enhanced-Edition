/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** AGraphicalComponent
*/

#include "AGraphicalComponent.hpp"

namespace nts
{
    AGraphicalComponent::AGraphicalComponent() noexcept:
        m_highlighted{false},
        m_clicked{false},
        m_moving{false},
        m_click_pos{0, 0}
    {
    }

    IComponent *AGraphicalComponent::get() noexcept
    {
        return getInternalComponent();
    }

    const IComponent *AGraphicalComponent::get() const noexcept
    {
        return getInternalComponent();
    }

    const std::string &AGraphicalComponent::getName() const noexcept
    {
        return m_name;
    }

    void AGraphicalComponent::setName(const std::string &name)
    {
        m_name = name;
    }

    sf::FloatRect AGraphicalComponent::getGlobalBounds() const
    {
        return getTransform().transformRect(getLocalBounds());
    }

    void AGraphicalComponent::removeHighlight() noexcept
    {
        m_highlighted = m_moving = m_clicked = false;
    }

    void AGraphicalComponent::keyPressedHandler(const sf::Event::KeyEvent &event)
    {
        if (m_highlighted) {
            keyReleasedAction(event);
        }
    }

    bool AGraphicalComponent::isHighlighted() const noexcept
    {
        return m_highlighted;
    }

    bool AGraphicalComponent::isClicked() const noexcept
    {
        return m_clicked;
    }

    bool AGraphicalComponent::isMoving() const noexcept
    {
        return m_moving;
    }

    void AGraphicalComponent::keyReleasedHandler(const sf::Event::KeyEvent &event)
    {
        if (m_highlighted) {
            keyReleasedAction(event);
        }
    }

    void AGraphicalComponent::mouseButtonPressedHandler(sf::Mouse::Button button, sf::Vector2f pos)
    {
        if (m_highlighted && !m_clicked && button == sf::Mouse::Left) {
            m_clicked = true;
            m_click_pos = pos;
        }
    }

    void AGraphicalComponent::mouseButtonReleasedHandler(sf::Mouse::Button button)
    {
        if (m_highlighted && m_clicked && button == sf::Mouse::Left) {
            m_clicked = false;
            if (!m_moving)
                mouseButtonClicked();
            m_moving = false;
        }
    }

    void AGraphicalComponent::mouseWheelHandler(sf::Mouse::Wheel wheel, float delta)
    {
        if (m_highlighted) {
            mouseWheelAction(wheel, delta);
        }
    }

    void AGraphicalComponent::mouseMoveHandler(sf::Vector2f pos)
    {
        sf::FloatRect global_bounds = getGlobalBounds();

        if (!m_moving) {
            m_highlighted = global_bounds.contains(pos);
            if (!m_highlighted)
                return;
        }
        m_moving = m_clicked;
        if (m_moving) {
            move(pos - m_click_pos);
            m_click_pos = pos;
        }
    }

    void AGraphicalComponent::keyPressedAction(const sf::Event::KeyEvent &)
    {
    }

    void AGraphicalComponent::keyReleasedAction(const sf::Event::KeyEvent &)
    {
    }

    void AGraphicalComponent::mouseButtonClicked()
    {
    }

    void AGraphicalComponent::mouseWheelAction(sf::Mouse::Wheel, float)
    {
    }

    void AGraphicalComponent::appyTransformations(sf::Transformable &transformable)
    {
        transformable.setOrigin(getOrigin());
        transformable.setPosition(getPosition());
        transformable.setRotation(getRotation());
        transformable.setScale(getScale());
    }

    IComponent *AGraphicalComponent::operator->() noexcept
    {
        return get();
    }

    const IComponent *AGraphicalComponent::operator->() const noexcept
    {
        return get();
    }

    IComponent &AGraphicalComponent::operator*() noexcept
    {
        return *get();
    }

    const IComponent &AGraphicalComponent::operator*() const noexcept
    {
        return *get();
    }
} // namespace nts

