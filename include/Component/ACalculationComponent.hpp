/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ACalculationComponent
*/

#ifndef ACALCULATIONCOMPONENT_HPP_
#define ACALCULATIONCOMPONENT_HPP_

#include "types.hpp"

namespace nts
{
    class ACalculationComponent: public nts::IComponent {
        public:
            ACalculationComponent(nts::ComponentType type, std::size_t nb_pins,
                                  const pinList_t &input_pins, const pinList_t &output_pins) noexcept;

            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const final;

        protected:
            void addInternalComponent(IComponent &component);
            virtual void computeOutputs() = 0;

        protected:
            nts::ComponentType        m_type;
            const nts::componentPin_t m_input_pins;
            nts::pinMap_t             m_output_pins;

        private:
            std::size_t               m_actual_tick;
            std::vector<nts::Link>    m_links;
            std::vector<IComponent *> m_internal_components;
            
    };
}

#endif /* !ACALCULATIONCOMPONENT_HPP_ */
