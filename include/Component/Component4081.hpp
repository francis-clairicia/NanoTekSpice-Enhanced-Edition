/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include <list>
#include "IComponent.hpp"
#include "definitions.hpp"

namespace nts
{
    class Component4081: public nts::IComponent {
        public:
            Component4081();
            ~Component4081();

            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const final;

        private:
            std::string m_type;
            nts::component_link_t<14> m_internal_links;
            nts::component_link_t<14> m_external_links;
            nts::intern_component_t<4>  m_components;
            const nts::component_pin_t<8> m_input_pins;
            const nts::component_pin_t<4> m_output_pins;
    };
}

#endif /* !COMPONENT4081_HPP_ */
