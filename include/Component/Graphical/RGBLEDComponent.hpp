/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** RGBLEDComponent
*/

#ifndef RGBLEDCOMPONENT_HPP_
#define RGBLEDCOMPONENT_HPP_

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "AGraphicalComponent.hpp"
#include "ACalculationComponent.hpp"

namespace nts
{
    class RGBLEDComponent: public AGraphicalComponent
    {
    public:
        RGBLEDComponent();
        ~RGBLEDComponent() noexcept override = default;

        void update() noexcept override;

        sf::FloatRect getLocalBounds() const final;

    protected:
        IComponent *getInternalComponent() const noexcept final;

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const final;

    private:
        class RGBComponent final: public ACalculationComponent
        {
        public:
            enum PinName
            {
                INPUT_R = 1,
                INPUT_G = 2,
                INPUT_B = 3,
            };

        public:
            RGBComponent();
            ~RGBComponent() noexcept override = default;

            [[nodiscard]] sf::Uint32 makeColor() const noexcept;

        private:
            void computeOutputs() final;

        private:
            bool m_red;
            bool m_green;
            bool m_blue;
        };

    private:
        std::unique_ptr<RGBComponent> m_component;
        sf::CircleShape               m_led;
        sf::Text                      m_text;
        sf::RectangleShape            m_box;
    };
} // namespace nts

#endif /* !RGBLEDCOMPONENT_HPP_ */
