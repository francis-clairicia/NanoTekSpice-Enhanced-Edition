/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#ifndef ONEINPUTGATE_HPP_
#define ONEINPUTGATE_HPP_

#include "IGate.hpp"

namespace nts
{
    class OneInputGate: public IGate {
        public:
            OneInputGate(std::size_t input_pin) noexcept;
            virtual ~OneInputGate() override;

            nts::Tristate compute(const std::string &component_name, nts::component_link_t &links) const final;
            virtual nts::Tristate operation(nts::Tristate a) const = 0;

        private:
            std::size_t m_input_pin;
    };
}

#endif /* !ONEINPUTGATE_HPP_ */
