/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** SevenSegmentComponent
*/

#include <SFML/Graphics/RectangleShape.hpp>
#include "SevenSegmentComponent.hpp"
#include "ResourcesManager.hpp"

namespace
{
    const std::unordered_map<std::string_view, std::string> SEGMENTS{
        {"all_red", "./assets/img/7seg_all_red.png"},
        {"all_white", "./assets/img/7seg_all_white.png"},
        {"a", "./assets/img/7seg_a.png"},
        {"b", "./assets/img/7seg_b.png"},
        {"c", "./assets/img/7seg_c.png"},
        {"d", "./assets/img/7seg_d.png"},
        {"e", "./assets/img/7seg_e.png"},
        {"f", "./assets/img/7seg_f.png"},
        {"g", "./assets/img/7seg_g.png"},
    };
} // namespace


namespace nts
{
    SevenSegmentComponent::SevenSegmentComponent():
        ACalculationComponent{ComponentType::ThirdParty, 7, {
            INPUT_A, INPUT_B, INPUT_C, INPUT_D, INPUT_E, INPUT_F, INPUT_G
        }, {}}
    {
        for (const auto &pair : SEGMENTS) {
            m_segments.emplace(pair.first, ResourcesManager::loadImage(pair.second));
            m_showed_segments.emplace(pair.first, false);
        }
        setScale({0.20, 0.20});
    }

    void SevenSegmentComponent::computeOutputs()
    {
        static const std::unordered_map<std::string, PinName> INPUTS
        {
            {"a", INPUT_A},
            {"b", INPUT_B},
            {"c", INPUT_C},
            {"d", INPUT_D},
            {"e", INPUT_E},
            {"f", INPUT_F},
            {"g", INPUT_G}
        };

        for (const auto &pair : INPUTS) {
            m_showed_segments[pair.first] = (compute(pair.second) == TRUE);
        }
    }

    void SevenSegmentComponent::update() noexcept
    {
        for (auto &pair : m_segments) {
            appyTransformations(pair.second);
        }

    }

    sf::FloatRect SevenSegmentComponent::getLocalBounds() const
    {
        return m_segments.at("all_white").getLocalBounds();
    }

    IComponent *SevenSegmentComponent::getInternalComponent() const noexcept
    {
        return const_cast<SevenSegmentComponent *>(this);
    }

    void SevenSegmentComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_segments.at("all_white"));
        for (const char *segment : {"a", "b", "c", "d", "e", "f", "g"}) {
            if (m_showed_segments.at(segment)) {
                target.draw(m_segments.at(segment), states);
            }
        }

        sf::FloatRect bounds = getGlobalBounds();

        if (isHighlighted()) {
            sf::RectangleShape box{{bounds.width, bounds.height}};
            
            box.setPosition({bounds.left, bounds.top});
            box.setFillColor(sf::Color::Transparent);
            box.setOutlineColor(sf::Color::Yellow);
            box.setOutlineThickness(2);
            target.draw(box, states);
        }
    }
} // namespace nts
