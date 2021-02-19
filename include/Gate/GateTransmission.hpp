/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** GateTransmission
*/

#ifndef GATETRANSMISSION_HPP_
#define GATETRANSMISSION_HPP_

#include <queue>
#include "AGate.hpp"

namespace nts
{
    class GateTransmission: public nts::AGate {
        public:
            enum Pin
            {
                INPUT   = 1,
                CONTROL = 2,
                OUTPUT  = 3
            };

        public:
            GateTransmission() noexcept;

        protected:
            nts::Tristate computeOutput() final;

        private:
            std::queue<nts::Tristate> m_buffer;
    };
}

#endif /* !GATETRANSMISSION_HPP_ */
