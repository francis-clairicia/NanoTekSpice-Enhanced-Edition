/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_

#include <memory>
#include "InputComponent.hpp"

namespace nts
{
    class ClockComponent: public nts::InputComponent {
        public:
            ClockComponent();

            void simulate(std::size_t tick) final;
            void setValue(const std::string &value) final;
        
        private:
            std::size_t m_actual_tick;
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
