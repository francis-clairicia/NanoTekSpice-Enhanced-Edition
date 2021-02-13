/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** TwoInputsGate
*/

#ifndef TWOINPUTSGATE_HPP_
#define TWOINPUTSGATE_HPP_

#include "IGate.hpp"

namespace nts
{
    class TwoInputsGate: public IGate {
        public:
            TwoInputsGate(std::size_t input_pin1, std::size_t input_pin2);
            virtual ~TwoInputsGate() override;

            nts::Tristate compute(const std::string &component_name, nts::component_link_t &links) const final;
            virtual nts::Tristate operation(nts::Tristate a, nts::Tristate b) const = 0;

        private:
            std::size_t m_input_pin1;
            std::size_t m_input_pin2;
    };
}

#endif /* !TWOINPUTSGATE_HPP_ */
