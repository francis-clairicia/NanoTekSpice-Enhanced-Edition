/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SumComponent
*/

#ifndef SUMCOMPONENT_HPP_
#define SUMCOMPONENT_HPP_

#include "BoxComponent.hpp"

namespace nts
{
    class SumComponent: public nts::BoxComponent {
        public:
            enum PinName
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

        protected:
            void dumpInternalComponents() const final;

        private:
            std::unique_ptr<nts::IComponent> m_xor1;
            std::unique_ptr<nts::IComponent> m_xor2;
            std::unique_ptr<nts::IComponent> m_and1;
            std::unique_ptr<nts::IComponent> m_and2;
            std::unique_ptr<nts::IComponent> m_or;
    };
}

#endif /* !SUMCOMPONENT_HPP_ */