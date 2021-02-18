/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <initializer_list>
#include <string>
#include <vector>
#include <utility>
#include <memory>
#include "IComponent.hpp"

namespace nts
{
    class AComponent: public nts::IComponent {
        public:
            using component_link_t = std::pair<IComponent *, std::size_t>;
            using component_vector_link_t = std::vector<component_link_t>;
            using intern_component_t = std::vector<std::unique_ptr<IComponent>>;
            using component_pin_t = std::vector<std::size_t>;
            using pin_list_t = std::initializer_list<std::size_t>;

        public:
            AComponent(const std::string &type, std::size_t nb_pins, const pin_list_t &input_pins, const pin_list_t &output_pins) noexcept;

            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const override;
        
        protected:
            void setLinkInternal(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void dumpExternalLinks() const;
            void dumpInternalLinks() const;

        protected:
            std::string             m_type;
            component_vector_link_t m_internal_links;
            component_vector_link_t m_external_links;
            intern_component_t      m_components;
            const component_pin_t   m_input_pins;
            const component_pin_t   m_output_pins;
    };
}

#endif /* !ACOMPONENT_HPP_ */
