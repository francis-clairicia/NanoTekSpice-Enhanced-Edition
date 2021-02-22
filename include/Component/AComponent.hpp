/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "types.hpp"

namespace nts
{
    class AComponent: public nts::IComponent {
        public:
            AComponent(nts::ComponentType type, std::size_t nb_pins, const pinList_t &input_pins, const pinList_t &output_pins) noexcept;

            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const final;
        
        protected:
            void setLinkInternal(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            virtual void dumpInternalComponents() const = 0;

        protected:
            nts::ComponentType   m_type;
            const nts::componentPin_t m_input_pins;
            const nts::componentPin_t m_output_pins;

        private:
            std::vector<nts::Link>    m_internal_links;
            std::vector<nts::Link>    m_external_links;
    };
}

#endif /* !ACOMPONENT_HPP_ */
