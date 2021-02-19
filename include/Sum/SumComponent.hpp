/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SumComponent
*/

#ifndef SUMCOMPONENT_HPP_
#define SUMCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class SumComponent: public nts::AComponent {
        public:
            enum Pin
            {
                Ai = 1,
                Bi = 2,
                Ci = 3,
                Co = 4,
                Si = 5
            };

        public:
            SumComponent() noexcept;
            ~SumComponent();

            void simulate(std::size_t tick) final;

        protected:
            void dumpInternalComponents() const final;

        private:
            std::unique_ptr<IComponent> m_xor1;
            std::unique_ptr<IComponent> m_xor2;
            std::unique_ptr<IComponent> m_and1;
            std::unique_ptr<IComponent> m_and2;
            std::unique_ptr<IComponent> m_or;
    };
}

#endif /* !SUMCOMPONENT_HPP_ */
