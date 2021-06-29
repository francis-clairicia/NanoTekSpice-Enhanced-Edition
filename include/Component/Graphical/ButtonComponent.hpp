/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ButtonComponent
*/

#ifndef BUTTONCOMPONENT_HPP_
#define BUTTONCOMPONENT_HPP_

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "AGraphicalComponent.hpp"
#include "InputComponent.hpp"

namespace nts
{
    class ButtonComponent: public AGraphicalComponent
    {
    public:
        using Component = std::unique_ptr<InputComponent>;

    public:
        ButtonComponent();
        ~ButtonComponent() noexcept override = default;

        void update() noexcept override;

        sf::FloatRect getLocalBounds() const final;

    protected:
        IComponent *getInternalComponent() const noexcept final;

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const final;

    private:
        Component       m_component;
        sf::CircleShape m_button;
        sf::Text        m_text;
    };
} // namespace nts

#endif /* !BUTTONCOMPONENT_HPP_ */
