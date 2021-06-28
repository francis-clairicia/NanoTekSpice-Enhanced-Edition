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
        m_moving{false}
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

    sf::FloatRect AGraphicalComponent::getGlobalBounds() const
    {
        return getTransform().transformRect(getLocalBounds());
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

    void AGraphicalComponent::keyReleasedHandler(const sf::Event::KeyEvent &event)
    {
        if (m_highlighted) {
            keyReleasedAction(event);
        }
    }

    void AGraphicalComponent::mouseButtonPressedHandler(sf::Mouse::Button button)
    {
        if (m_highlighted && !m_clicked && button == sf::Mouse::Left) {
            m_clicked = true;
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
        sf::FloatRect local_bounds = getLocalBounds();
        sf::FloatRect global_bounds = getGlobalBounds();

        if (!m_highlighted) {
            m_highlighted = global_bounds.contains(pos);
            if (!m_highlighted)
                return;
        }
        m_moving = m_clicked;
        if (m_moving) {
            setOrigin({local_bounds.width / 2, local_bounds.height / 2});
            setPosition(pos);
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

