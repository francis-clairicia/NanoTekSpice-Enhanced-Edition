/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4017
*/

#ifndef COMPONENT4017_HPP_
#define COMPONENT4017_HPP_

#include "AComponent.hpp"

namespace nts
{
    class Component4017: public nts::AComponent {
        public:
            enum Pin
            {
                Q5    = 1,
                Q1    = 2,
                Q0    = 3,
                Q2    = 4,
                Q6    = 5,
                Q7    = 6,
                Q3    = 7,
                Q8    = 9,
                Q4    = 10,
                Q9    = 11,
                Q5_9 = 12,
                CP1   = 13,
                CP0   = 14,
                MR    = 15
            };

        public:
            Component4017() noexcept;
            ~Component4017() noexcept;

            void simulate(std::size_t tick) final;

        protected:
            void dumpInternalComponents() const final;
        
        private:
            std::unique_ptr<IComponent> m_ground;
            std::unique_ptr<IComponent> m_buffer_last_flipflop;
            std::unique_ptr<IComponent> m_buffer_flipflop_0_1;
            std::unique_ptr<IComponent> m_buffer_flipflop_1_2;
            std::unique_ptr<IComponent> m_buffer_flipflop_2_3;
            std::unique_ptr<IComponent> m_buffer_flipflop_3_4;
            std::unique_ptr<IComponent> m_inverter_cp1;
            std::unique_ptr<IComponent> m_and_gate_clock;
            std::unique_ptr<IComponent> m_and_gate_data;
            std::unique_ptr<IComponent> m_or_gate_data;
            nts::internComponent_t      m_flipflops;
            nts::internComponent_t      m_nor;
    };
}

#endif /* !COMPONENT4017_HPP_ */
