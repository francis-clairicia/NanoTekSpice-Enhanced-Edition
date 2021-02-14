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
#include "GateNOT.hpp"

namespace nts
{
    class ClockComponent: public nts::InputComponent {
        public:
            ClockComponent();

            void simulate(std::size_t tick) final;
        
        private:
            std::size_t m_actual_tick;
            std::unique_ptr<nts::GateNOT> m_gate;
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
