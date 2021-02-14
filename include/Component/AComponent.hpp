/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <initializer_list>
#include "IComponent.hpp"
#include "definitions.hpp"

namespace nts
{
    class AComponent: public nts::IComponent {
        public:
            AComponent(const std::string &type, std::size_t nb_pins, const pin_list_t &input_pins, const pin_list_t &output_pins) noexcept;

            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const override;
        
        protected:
            void setLinkInternal(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        protected:
            std::string                m_type;
            nts::component_link_t      m_internal_links;
            nts::component_link_t      m_external_links;
            nts::intern_component_t    m_components;
            const nts::component_pin_t m_input_pins;
            const nts::component_pin_t m_output_pins;
    };
}

#endif /* !ACOMPONENT_HPP_ */
