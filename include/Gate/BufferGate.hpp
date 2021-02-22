/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** BufferGate
*/

#ifndef BUFFERGATE_HPP_
#define BUFFERGATE_HPP_

#include "AGate.hpp"

namespace nts
{
    class BufferGate: public nts::AGate {
        public:
            enum Pin
            {
                INPUT = 1,
                OUTPUT = 2
            };

        public:
            BufferGate() noexcept;

            void simulate(std::size_t tick) override;

        protected:
            nts::Tristate computeOutput(std::size_t pin) final;

        private:
            nts::Tristate m_buffer;
    };
}

#endif /* !BUFFERGATE_HPP_ */
