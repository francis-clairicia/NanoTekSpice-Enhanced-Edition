/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace nts
{
    class Camera
    {
    public:
        Camera(sf::RenderWindow &window) noexcept;
        ~Camera() noexcept = default;

        void reset();

        void move(sf::Vector2f offset);
        void moveEvent(sf::Mouse::Button button, sf::Vector2i pos, bool click);
        void moveEvent(sf::Vector2i pos);
        [[nodiscard]] bool isMoving() const noexcept;

        void resize(sf::Vector2f size);
        void resize(sf::Vector2u size);
        void resize(sf::Vector2i size);
        void resizeEvent(const sf::Event::SizeEvent &event);

        void zoom(float factor);
        void zoomEvent(const sf::Event::MouseWheelScrollEvent &event);

    private:
        sf::RenderWindow &m_window;
        sf::View          m_view;
        bool              m_clicked;
        bool              m_moving;
        sf::Vector2i      m_click_pos;
    };
} // namespace nts


#endif /* !CAMERA_HPP_ */
