/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GUINanoTekSpice
*/

#include "GUINanoTekSpice.hpp"
#include "Parser.hpp"

namespace nts
{
    GUINanoTekSpice::GUINanoTekSpice(const std::string &circuit_file):
        m_circuit{Parser::parse<GraphicalCircuit>(circuit_file)},
        m_highlighted_component{nullptr}
    {
    }

    void GUINanoTekSpice::run()
    {
        m_window.create({800, 800}, "NanoTekSpice - Enhanced Edition");

        while (m_window.isOpen()) {
            handleEvents();
            drawScreen();
        }
    }

    void GUINanoTekSpice::drawScreen()
    {
        m_window.clear();
        for (const auto &pair : m_circuit.m_graphical_components) {
            m_window.draw(pair.second);
        }
    }

    void GUINanoTekSpice::handleEvents()
    {
        sf::Event event;

        while (m_window.pollEvent(event)) {
            switch (event.type)
            {
            case sf::Event::Closed:
                closeWindow();
                break;
            case sf::Event::KeyPressed:
                keyPressedHandler(event.key);
                break;
            case sf::Event::KeyReleased:
                keyReleasedHandler(event.key);
                break;
            case sf::Event::MouseButtonPressed:
                mouseButtonPressedHandler(event.mouseButton);
                break;
            case sf::Event::MouseButtonReleased:
                mouseButtonReleasedHandler(event.mouseButton);
                break;
            case sf::Event::MouseMoved:
                mouseMoveHandler(event.mouseMove);
                break;
            case sf::Event::MouseWheelScrolled:
                mouseWheelHandler(event.mouseWheelScroll);
                break;
            case sf::Event::Resized:
                resizeHandler(event.size);
                break;
            default:
                break;
            }
        }
    }

    sf::Vector2f GUINanoTekSpice::getMousePosition() const noexcept
    {
        return getMousePosition(sf::Mouse::getPosition(m_window));
    }

    sf::Vector2f GUINanoTekSpice::getMousePosition(sf::Vector2i mouse_pos) const noexcept
    {
        return m_window.mapPixelToCoords(mouse_pos);
    }

    void GUINanoTekSpice::closeWindow()
    {
        m_window.close();
    }

    void GUINanoTekSpice::keyPressedHandler(const sf::Event::KeyEvent &event)
    {
        processComponentEvent(&AGraphicalComponent::keyPressedHandler, event);
    }

    void GUINanoTekSpice::keyReleasedHandler(const sf::Event::KeyEvent &event)
    {
        processComponentEvent(&AGraphicalComponent::keyReleasedHandler, event);
    }

    void GUINanoTekSpice::mouseButtonPressedHandler(const sf::Event::MouseButtonEvent &event)
    {
        processComponentEvent(&AGraphicalComponent::mouseButtonPressedHandler, event.button);
    }

    void GUINanoTekSpice::mouseButtonReleasedHandler(const sf::Event::MouseButtonEvent &event)
    {
        processComponentEvent(&AGraphicalComponent::mouseButtonReleasedHandler, event.button);
    }

    void GUINanoTekSpice::mouseMoveHandler(const sf::Event::MouseMoveEvent &event)
    {
        processComponentEvent(&AGraphicalComponent::mouseMoveHandler, getMousePosition({event.x, event.y}));
    }

    void GUINanoTekSpice::mouseWheelHandler(const sf::Event::MouseWheelScrollEvent &event)
    {
        processComponentEvent(&AGraphicalComponent::mouseWheelHandler, event.wheel, event.delta);
    }

    void GUINanoTekSpice::resizeHandler(const sf::Event::SizeEvent &event)
    {
        m_window.setView(sf::View{sf::FloatRect{0, 0, static_cast<float>(event.width), static_cast<float>(event.height)}});
    }
} // namespace nts
