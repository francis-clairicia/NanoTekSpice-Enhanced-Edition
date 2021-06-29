/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** RGBLEDComponent
*/

#include "RGBLEDComponent.hpp"
#include "ResourcesManager.hpp"

namespace nts
{
    RGBLEDComponent::RGBLEDComponent():
        m_component{std::make_unique<RGBComponent>()}
    {
        m_text.setFont(ResourcesManager::loadFont(FONT_FILE.data()));
        m_text.setCharacterSize(25);
        m_text.setFillColor(sf::Color::White);
        m_led.setRadius(30);
        m_box.setOutlineColor(sf::Color::Transparent);
        m_box.setOutlineThickness(2);
        m_box.setFillColor(sf::Color::Transparent);
    }

    void RGBLEDComponent::update() noexcept
    {
        m_led.setFillColor(sf::Color{m_component->makeColor()});
        m_text.setString(getName());

        sf::FloatRect led_bounds_global = m_led.getGlobalBounds();
        sf::FloatRect led_bounds = m_led.getLocalBounds();
        sf::FloatRect text_bounds_global = m_text.getGlobalBounds();
        sf::FloatRect text_bounds = m_text.getGlobalBounds();

        m_box.setSize({
            std::max(led_bounds_global.width, text_bounds_global.width) * 1.1f,
            led_bounds_global.height + text_bounds_global.height * 2.f
        });

        appyTransformations(m_box);

        sf::FloatRect bounds = getGlobalBounds();

        m_led.setOrigin({led_bounds.width / 2, 0});
        m_led.setPosition({bounds.left + bounds.width / 2, bounds.top});

        m_text.setOrigin({text_bounds.width / 2, text_bounds.height});
        m_text.setPosition({bounds.left + bounds.width / 2, bounds.top + bounds.height * 0.9f});

        if (isHighlighted()) {
            m_box.setOutlineColor(sf::Color::Yellow);
        } else {
            m_box.setOutlineColor(sf::Color::Transparent);
        }
    }

    sf::FloatRect RGBLEDComponent::getLocalBounds() const
    {
        return m_box.getLocalBounds();
    }

    IComponent *RGBLEDComponent::getInternalComponent() const noexcept
    {
        return m_component.get();
    }

    void RGBLEDComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_led, states);
        target.draw(m_text, states);
        target.draw(m_box, states);
    }

    RGBLEDComponent::RGBComponent::RGBComponent():
        ACalculationComponent{ComponentType::ThirdParty, 3, {INPUT_R, INPUT_G, INPUT_B}, {}},
        m_red{false},
        m_green{false},
        m_blue{false}
    {
    }

    sf::Uint32 RGBLEDComponent::RGBComponent::makeColor() const noexcept
    {
        sf::Uint32 red   = 0xFF000000;
        sf::Uint32 green = 0x00FF0000;
        sf::Uint32 blue  = 0x0000FF00;
        sf::Uint32 color = 0x000000FF;

        if (m_red)
            color |= red;
        if (m_green)
            color |= green;
        if (m_blue)
            color |= blue;
        return color;
    }

    void RGBLEDComponent::RGBComponent::computeOutputs()
    {
        m_red = (compute(INPUT_R) == TRUE);
        m_green = (compute(INPUT_G) == TRUE);
        m_blue = (compute(INPUT_B) == TRUE);
    }
} // namespace nts
