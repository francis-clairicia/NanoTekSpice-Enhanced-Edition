/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** DTypeFlipFlopWithSR
*/

#ifndef DTYPEFLIPFLOPWITHSR_HPP_
#define DTYPEFLIPFLOPWITHSR_HPP_

#include "AComponent.hpp"
#include "AGate.hpp"

namespace nts
{
    class DTypeFlipFlopWithSR: public nts::AComponent {
        public:
            enum Pin
            {
                Q     = 1,
                Qn    = 2,
                CLOCK = 3,
                RESET = 4,
                DATA  = 5,
                SET   = 6
            };

        public:
            DTypeFlipFlopWithSR() noexcept;
            ~DTypeFlipFlopWithSR();

            void simulate(std::size_t tick) final;

        protected:
            void dumpInternalComponents() const final;

        private:
            std::unique_ptr<IComponent> m_tg1;
            std::unique_ptr<IComponent> m_tg2;
            std::unique_ptr<IComponent> m_tg3;
            std::unique_ptr<IComponent> m_tg4;
            std::unique_ptr<IComponent> m_inverter_clock;
            std::unique_ptr<IComponent> m_inverter1;
            std::unique_ptr<IComponent> m_inverter2;
            std::unique_ptr<IComponent> m_nor1;
            std::unique_ptr<IComponent> m_nor2;
            std::unique_ptr<IComponent> m_nor3;
            std::unique_ptr<IComponent> m_nor4;
            std::unique_ptr<IComponent> m_node1;
            std::unique_ptr<IComponent> m_node2;
            std::unique_ptr<IComponent> m_memoryQ;
            std::unique_ptr<IComponent> m_memoryQn;

        private:
            class MemoryGate: public nts::AGate {
                public:
                    enum Pin
                    {
                        INPUT  = 1,
                        CLOCK  = 2,
                        RESET  = 3,
                        SET    = 4,
                        OUTPUT = 5
                    };

                public:
                    MemoryGate() noexcept;

                protected:
                    nts::Tristate computeOutput() final;

                private:
                    nts::Tristate m_buffer;
            };
    };
}

#endif /* !DTYPEFLIPFLOPWITHSR_HPP_ */
