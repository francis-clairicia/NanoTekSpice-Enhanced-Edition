/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** AGraphicalComponent
*/

#ifndef AGRAPHICALCOMPONENT_HPP_
#define AGRAPHICALCOMPONENT_HPP_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Window/Event.hpp>
#include "IComponent.hpp"

namespace nts
{
    class AGraphicalComponent: public sf::Drawable, public sf::Transformable
    {
    public:
        AGraphicalComponent() noexcept;
        ~AGraphicalComponent() noexcept override = default;

        IComponent *get() noexcept;
        const IComponent *get() const noexcept;

        virtual void update(const std::string &component_name) noexcept = 0;

        virtual sf::FloatRect getLocalBounds() const = 0;
        sf::FloatRect getGlobalBounds() const;

        [[nodiscard]] bool isHighlighted() const noexcept;
        [[nodiscard]] bool isClicked() const noexcept;

        void removeHighlight() noexcept;

        void keyPressedHandler(const sf::Event::KeyEvent &event);
        void keyReleasedHandler(const sf::Event::KeyEvent &event);
        void mouseButtonPressedHandler(sf::Mouse::Button button, sf::Vector2f pos);
        void mouseButtonReleasedHandler(sf::Mouse::Button button);
        void mouseWheelHandler(sf::Mouse::Wheel wheel, float delta);
        void mouseMoveHandler(sf::Vector2f pos);

        IComponent *operator->() noexcept;
        const IComponent *operator->() const noexcept;

        IComponent &operator*() noexcept;
        const IComponent &operator*() const noexcept;

    protected:
        virtual IComponent *getInternalComponent() const noexcept = 0;

        virtual void keyPressedAction(const sf::Event::KeyEvent &event);
        virtual void keyReleasedAction(const sf::Event::KeyEvent &event);
        virtual void mouseButtonClicked();
        virtual void mouseWheelAction(sf::Mouse::Wheel wheel, float delta);

    private:
        bool m_highlighted;
        bool m_clicked;
        bool m_moving;
        sf::Vector2f m_click_pos;
    };
} // namespace nts

#endif /* !AGRAPHICALCOMPONENT_HPP_ */
