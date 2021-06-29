/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GUINanoTekSpice
*/

#include <SFML/Graphics/RectangleShape.hpp>
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
        m_window.create({1366, 768}, "NanoTekSpice - Enhanced Edition");
        m_window.setFramerateLimit(60);

        while (m_window.isOpen()) {
            handleEvents();
            drawScreen();
            m_window.display();
        }
    }

    void GUINanoTekSpice::drawScreen()
    {
        m_window.clear(sf::Color{0, 5, 100});
        for (const auto &pair : m_circuit.m_graphical_components) {
            const std::unique_ptr<AGraphicalComponent> &component = pair.second;
            component->update(pair.first);
            m_window.draw(*component);
            if (component->isHighlighted()) {
                sf::FloatRect bounds = component->getGlobalBounds();
                sf::RectangleShape box{{bounds.width, bounds.height}};

                box.setFillColor(sf::Color::Transparent);
                box.setOutlineColor(sf::Color::Yellow);
                box.setOutlineThickness(2);
                box.setPosition({bounds.left, bounds.top});
                m_window.draw(box);
            }
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
        processComponentEvent(&AGraphicalComponent::mouseButtonPressedHandler, event.button, getMousePosition({event.x, event.y}));
    }

    void GUINanoTekSpice::mouseButtonReleasedHandler(const sf::Event::MouseButtonEvent &event)
    {
        processComponentEvent(&AGraphicalComponent::mouseButtonReleasedHandler, event.button);
    }

    void GUINanoTekSpice::mouseMoveHandler(const sf::Event::MouseMoveEvent &event)
    {
        processMoveComponentEvent(getMousePosition({event.x, event.y}));
    }

    void GUINanoTekSpice::mouseWheelHandler(const sf::Event::MouseWheelScrollEvent &event)
    {
        processComponentEvent(&AGraphicalComponent::mouseWheelHandler, event.wheel, event.delta);
    }

    void GUINanoTekSpice::resizeHandler(const sf::Event::SizeEvent &event)
    {
        m_window.setView(sf::View{sf::FloatRect{0, 0, static_cast<float>(event.width), static_cast<float>(event.height)}});
    }

    void GUINanoTekSpice::processMoveComponentEvent(sf::Vector2f pos)
    {
        auto begin = m_circuit.m_graphical_components.begin();
        auto end = m_circuit.m_graphical_components.end();

        if (m_highlighted_component) {
            if (m_highlighted_component->isClicked()) {
                m_highlighted_component->mouseMoveHandler(pos);
                return;
            }
            m_highlighted_component->removeHighlight();
            m_highlighted_component = nullptr;
        }
        for (auto pair = begin; pair != end; ++pair) {
            AGraphicalComponent &component = *(pair->second);
            component.mouseMoveHandler(pos);
            if (component.isHighlighted()) {
                if (m_highlighted_component)
                    m_highlighted_component->removeHighlight();
                m_highlighted_component = &component;
            }
        }
    }
} // namespace nts
