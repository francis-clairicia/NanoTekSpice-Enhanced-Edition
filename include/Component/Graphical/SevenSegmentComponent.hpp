/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** SevenSegmentComponent
*/

#ifndef SEVENSEGMENTCOMPONENT_HPP_
#define SEVENSEGMENTCOMPONENT_HPP_

#include <SFML/Graphics/Sprite.hpp>
#include "AGraphicalComponent.hpp"
#include "ACalculationComponent.hpp"

namespace nts
{
    class SevenSegmentComponent: public ACalculationComponent, public AGraphicalComponent
    {
    public:
        enum PinName
        {
            INPUT_A = 1,
            INPUT_B = 2,
            INPUT_C = 3,
            INPUT_D = 4,
            INPUT_E = 5,
            INPUT_F = 6,
            INPUT_G = 7,
        };

    public:
        SevenSegmentComponent();
        ~SevenSegmentComponent() noexcept override = default;

        void update() noexcept override;

        sf::FloatRect getLocalBounds() const final;

    protected:
        void computeOutputs() final;

        IComponent *getInternalComponent() const noexcept final;

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const final;

    private:
        std::unordered_map<std::string, sf::Sprite>          m_segments;
        std::unordered_map<std::string, bool>                m_showed_segments;
    };
} // namespace nts

#endif /* !SEVENSEGMENTCOMPONENT_HPP_ */
