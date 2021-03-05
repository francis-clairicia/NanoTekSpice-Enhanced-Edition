/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "SinglePinComponent.hpp"

namespace nts
{
    class InputComponent: public nts::SinglePinComponent {
        public:
            enum Pin
            {
                OUTPUT = 1
            };

        public:
            InputComponent(nts::ComponentType type = ComponentType::Input) noexcept;

            void simulate(std::size_t tick) override;
            void dump() const override;

            virtual void setValue(nts::Tristate value);

        protected:
            std::size_t   m_actual_tick;
            nts::Tristate m_value_for_next_tick;
    };  
}


#endif /* !INPUTCOMPONENT_HPP_ */
