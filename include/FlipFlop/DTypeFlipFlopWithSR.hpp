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
            std::unique_ptr<IComponent> m_gateQ;

        public:
            class QGate: public nts::AGate {
                public:
                    enum Pin
                    {
                        DATA   = 1,
                        CLOCK  = 2,
                        RESET  = 3,
                        SET    = 4,
                        Q      = 5,
                        Qn     = 6
                    };

                public:
                    QGate() noexcept;

                protected:
                    nts::Tristate computeOutput(std::size_t pin) final;

                private:
                    nts::Tristate m_Q_buffer;
                    nts::Tristate m_Qn_buffer;
            };
    };
}

#endif /* !DTYPEFLIPFLOPWITHSR_HPP_ */
