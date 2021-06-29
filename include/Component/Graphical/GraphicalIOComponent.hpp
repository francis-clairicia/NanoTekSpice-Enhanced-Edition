/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalIOComponent
*/

#ifndef GRAPHICALIOCOMPONENT_HPP_
#define GRAPHICALIOCOMPONENT_HPP_

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "AGraphicalComponent.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "ResourcesManager.hpp"

namespace
{
    const std::unordered_map<nts::Tristate, std::string_view> TRISTATE_TO_STR{
        {nts::FALSE,     "0"},
        {nts::TRUE,      "1"},
        {nts::UNDEFINED, "U"}
    };
} // namespace

namespace nts
{
    template<typename IOComponent>
    class GraphicalIOComponent: public AGraphicalComponent
    {
    public:
        static_assert(std::is_base_of_v<InputComponent, IOComponent> || std::is_base_of_v<OutputComponent, IOComponent>);

    public:
        using Component = std::unique_ptr<IOComponent>;

    public:
        GraphicalIOComponent():
            m_component{std::make_unique<IOComponent>()},
            m_text{TRISTATE_TO_STR.at(m_component->getValue()).data(), ResourcesManager::loadFont(FONT_FILE.data()), 25}
        {
        }

        ~GraphicalIOComponent() noexcept override = default;

        void update() noexcept override
        {
            m_text.setString(getName() + "\nValue: " + TRISTATE_TO_STR.at(m_component->getValue()).data());

            sf::FloatRect text_bounds = m_text.getLocalBounds();

            m_text.setOrigin({text_bounds.width / 2, text_bounds.height / 1.5f});
            m_box.setSize({text_bounds.width * 1.20f, text_bounds.height * 1.70f});
            m_box.setOrigin(getOrigin());
            m_box.setPosition(getPosition());

            sf::FloatRect box_bounds = m_box.getGlobalBounds();

            m_text.setPosition({box_bounds.left + box_bounds.width / 2, box_bounds.top + box_bounds.height / 2});
        }

        sf::FloatRect getLocalBounds() const final
        {
            return m_box.getLocalBounds();
        }

    protected:
        IComponent *getInternalComponent() const noexcept final
        {
            return m_component.get();
        }

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const final
        {
            target.draw(m_box, states);
            target.draw(m_text, states);
        }

    protected:
        Component          m_component;
        sf::Text           m_text;
        sf::RectangleShape m_box;
    };
} // namespace nts


#endif /* !GRAPHICALIOCOMPONENT_HPP_ */
