/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalInputComponent
*/

#ifndef GRAPHICALINPUTCOMPONENT_HPP_
#define GRAPHICALINPUTCOMPONENT_HPP_

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "AGraphicalComponent.hpp"
#include "InputComponent.hpp"

namespace nts
{
    class GraphicalInputComponent: public AGraphicalComponent
    {
    public:
        using Component = std::unique_ptr<InputComponent>;

    public:
        GraphicalInputComponent();
        ~GraphicalInputComponent() noexcept override = default;

        sf::FloatRect getLocalBounds() const final;

    protected:
        IComponent *getInternalComponent() const noexcept final;

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const final;

    private:
        Component          m_component;
        sf::Text           m_text;
        sf::RectangleShape m_box;
    };
} // namespace nts

#endif /* !GRAPHICALINPUTCOMPONENT_HPP_ */
