/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Camera
*/

#include "Camera.hpp"

namespace nts
{
    Camera::Camera(sf::RenderWindow &window) noexcept:
        m_window{window},
        m_view{window.getView()},
        m_clicked{false},
        m_moving{false},
        m_click_pos{0, 0}
    {
    }

    void Camera::reset()
    {
        sf::Vector2u window_size = m_window.getSize();
        sf::Vector2f size{static_cast<float>(window_size.x), static_cast<float>(window_size.y)};
        m_view.reset({0, 0, size.x, size.y});
        m_window.setView(m_view);
    }

    void Camera::move(sf::Vector2f offset)
    {
        m_view.move(offset);
        m_window.setView(m_view);
    }

    void Camera::moveEvent(sf::Mouse::Button button, sf::Vector2i pos, bool click)
    {
        if (click) {
            if (!m_clicked && button == sf::Mouse::Left) {
                m_clicked = true;
                m_moving = true;
                m_click_pos = pos;
            }
        } else {
            if (m_clicked && button == sf::Mouse::Left) {
                m_clicked = false;
                m_moving = false;
            }
        }
    }

    void Camera::moveEvent(sf::Vector2i pos)
    {
        if (m_moving) {
            sf::Vector2i offset = m_click_pos - pos;
            move({static_cast<float>(offset.x), static_cast<float>(offset.y)});
            m_click_pos = pos;
        }
    }

    bool Camera::isMoving() const noexcept
    {
        return m_moving;
    }

    void Camera::resize(sf::Vector2f size)
    {
        m_view.setSize(size);
        m_window.setView(m_view);
    }

    void Camera::resize(sf::Vector2u size)
    {
        resize(sf::Vector2f{static_cast<float>(size.x), static_cast<float>(size.y)});
    }

    void Camera::resize(sf::Vector2i size)
    {
        resize(sf::Vector2f{static_cast<float>(size.x), static_cast<float>(size.y)});
    }

    void Camera::resizeEvent(const sf::Event::SizeEvent &event)
    {
        resize(sf::Vector2u{event.width, event.height});
    }

    void Camera::zoom(float factor)
    {
        m_view.zoom(factor);
        m_window.setView(m_view);
    }

    void Camera::zoomEvent(const sf::Event::MouseWheelScrollEvent &event)
    {
        zoom(1 + (0.25 * (event.delta < 0 ? -1 : 1)));
    }
} // namespace nts
