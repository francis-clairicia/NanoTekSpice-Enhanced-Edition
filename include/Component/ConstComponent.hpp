/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ConstComponent
*/

#ifndef CONSTCOMPONENT_HPP_
#define CONSTCOMPONENT_HPP_

#include "InputComponent.hpp"

namespace nts
{
    class ConstComponent: public nts::InputComponent {
        public:
            ConstComponent(const std::string &type, nts::Tristate value);

            void setValue(nts::Tristate value) final;
    };
}

#endif /* !CONSTCOMPONENT_HPP_ */
