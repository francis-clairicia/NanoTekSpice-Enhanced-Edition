/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GUINanoTekSpice
*/

#ifndef GUINANOTEKSPICE_HPP_
#define GUINANOTEKSPICE_HPP_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "NanoTekSpice.hpp"
#include "GraphicalCircuit.hpp"

namespace nts
{
    class GUINanoTekSpice: public NanoTekSpice
    {
    public:
        GUINanoTekSpice(const std::string &circuit_file);
        GUINanoTekSpice(const GUINanoTekSpice &other) noexcept = delete;
        GUINanoTekSpice(GUINanoTekSpice &&rhs) noexcept = default;
        ~GUINanoTekSpice() noexcept override = default;

        void run() final;

        GUINanoTekSpice &operator=(const GUINanoTekSpice &other) noexcept = delete;
        GUINanoTekSpice &operator=(GUINanoTekSpice &&rhs) noexcept = default;

    private:
        void drawScreen();
        void handleEvents();

        sf::Vector2f getMousePosition() const noexcept;
        sf::Vector2f getMousePosition(sf::Vector2i mouse_pos) const noexcept;

        void closeWindow();
        void keyPressedHandler(const sf::Event::KeyEvent &event);
        void keyReleasedHandler(const sf::Event::KeyEvent &event);
        void mouseButtonPressedHandler(const sf::Event::MouseButtonEvent &event);
        void mouseButtonReleasedHandler(const sf::Event::MouseButtonEvent &event);
        void mouseMoveHandler(const sf::Event::MouseMoveEvent &event);
        void mouseWheelHandler(const sf::Event::MouseWheelScrollEvent &event);
        void resizeHandler(const sf::Event::SizeEvent &event);

        template<typename Handler, typename... HandlerArgs>
        void processComponentEvent(Handler handler, HandlerArgs &&... args)
        {
            if (m_highlighted_component) {
                (m_highlighted_component->*(handler))(std::forward<HandlerArgs>(args)...);
                if (!(m_highlighted_component->isHighlighted()))
                    m_highlighted_component = nullptr;
            } else {
                auto begin = m_circuit.m_graphical_components.rbegin();
                auto end = m_circuit.m_graphical_components.rend();

                for (auto pair = begin; pair != end; ++pair) {
                    AGraphicalComponent &component = pair->second;
                    (component.*(handler))(std::forward<HandlerArgs>(args)...);
                    if (component.isHighlighted())
                        m_highlighted_component = &component;
                }
            }
        }

    private:
        GraphicalCircuit m_circuit;
        sf::RenderWindow m_window;
        AGraphicalComponent *m_highlighted_component;
    };
} // namespace nts


#endif /* !GUINANOTEKSPICE_HPP_ */
