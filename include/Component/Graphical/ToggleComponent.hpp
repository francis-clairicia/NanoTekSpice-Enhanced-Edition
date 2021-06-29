/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ToggleComponent
*/

#ifndef TOGGLECOMPONENT_HPP_
#define TOGGLECOMPONENT_HPP_

#include <SFML/Graphics/Sprite.hpp>
#include "AGraphicalComponent.hpp"
#include "InputComponent.hpp"

namespace nts
{
    class ToggleComponent: public AGraphicalComponent
    {
    public:
        using Component = std::unique_ptr<InputComponent>;

    public:
        ToggleComponent();
        ~ToggleComponent() noexcept override = default;

        void update() noexcept override;

        sf::FloatRect getLocalBounds() const final;

    protected:
        IComponent *getInternalComponent() const noexcept final;

        void mouseButtonClicked() override;

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const final;

    private:
        Component     m_component;
        nts::Tristate m_intern_value;
        sf::Sprite    m_sprite;
    };
} // namespace nts

#endif /* !TOGGLECOMPONENT_HPP_ */
