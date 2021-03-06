/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_

#include "InputComponent.hpp"

namespace nts
{
    class ClockComponent: public nts::InputComponent {
        public:
            ClockComponent() noexcept;

            void simulate(std::size_t tick) final;
            void setValue(nts::Tristate value) noexcept final;
        
        private:
            bool m_invert_value;
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
