/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** BoxComponent
*/

#ifndef BOXCOMPONENT_HPP_
#define BOXCOMPONENT_HPP_

#include "PinList.hpp"

namespace nts
{
    class BoxComponent: public nts::IComponent {
        public:
            BoxComponent(nts::ComponentType type, std::size_t nb_pins, const pinList_t &input_pins, const pinList_t &output_pins) noexcept;
            ~BoxComponent() noexcept = default;

            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const noexcept final;
        
        protected:
            void setLinkInternal(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            virtual void dumpInternalComponents() const noexcept;

        protected:
            const nts::ComponentType  m_type;

        private:
            std::size_t               m_actual_tick;
            nts::PinList              m_pins;
    };
}

#endif /* !BOXCOMPONENT_HPP_ */
