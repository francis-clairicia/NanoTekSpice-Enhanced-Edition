/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "IOComponent.hpp"

namespace nts
{
    class InputComponent: public nts::IOComponent {
        public:
            InputComponent() noexcept;

            nts::Tristate compute(std::size_t pin) final;
            void dump() const override;

            virtual void setValue(const std::string &value);
    };  
}


#endif /* !INPUTCOMPONENT_HPP_ */
