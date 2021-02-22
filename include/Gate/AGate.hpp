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
            AGate(nts::ComponentType type, std::size_t nb_pins, const pinList_t &input_pins, const pinList_t & output_pins) noexcept;

            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const final;

        protected:
            virtual nts::Tristate computeOutput(std::size_t pin) = 0;

        protected:
            std::unordered_map<std::size_t, nts::Tristate> m_value;
            nts::ComponentType                             m_type;
            bool                                           m_computed;

        private:
            std::size_t               m_actual_tick;
            nts::componentPin_t       m_computed_pins;
            std::vector<nts::Link>    m_links;
            const nts::componentPin_t m_input_pins;
            const nts::componentPin_t m_output_pins;
    };
}

#endif /* !AGATE_HPP_ */
