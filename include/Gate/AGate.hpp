/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AGate
*/

#ifndef AGATE_HPP_
#define AGATE_HPP_

#include "types.hpp"

namespace nts
{
    class AGate: public nts::IComponent {
        public:
            AGate(const std::string &type, std::size_t nb_pins, const pinList_t &input_pins, std::size_t output_pin) noexcept;

            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const final;

        protected:
            virtual nts::Tristate computeOutput() = 0;

        protected:
            nts::Tristate                m_value;
            std::string                  m_type;
            std::size_t                  m_actual_tick;
            bool                         m_computed;
            std::vector<componentLink_t> m_links;
            const componentPin_t        m_input_pins;
            std::size_t                  m_output_pin;
    };
}

#endif /* !AGATE_HPP_ */