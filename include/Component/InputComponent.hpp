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
            InputComponent() noexcept;

            void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) final;
            void dump() const override;

            virtual void setValue(nts::Tristate value);
    };  
}


#endif /* !INPUTCOMPONENT_HPP_ */
