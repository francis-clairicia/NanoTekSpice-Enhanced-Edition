/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ACalculationComponent
*/

#ifndef ACALCULATIONCOMPONENT_HPP_
#define ACALCULATIONCOMPONENT_HPP_

#include "PinList.hpp"

namespace nts
{
    class ACalculationComponent: public nts::IComponent {
        public:
            ACalculationComponent(nts::ComponentType type, std::size_t nb_pins,
                                  const pinList_t &input_pins, const pinList_t &output_pins) noexcept;
            ~ACalculationComponent() noexcept = default;

            void simulate(std::size_t tick) final;
            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const noexcept final;

        protected:
            nts::Tristate computeInternalComponent(nts::IComponent &component, std::size_t pin) const;
            virtual void computeOutputs(std::size_t tick) = 0;

        protected:
            const nts::ComponentType  m_type;
            nts::pinMap_t             m_output_pins;
            nts::PinList              m_pins;

        private:
            std::size_t               m_actual_tick;
            
    };
}

#endif /* !ACALCULATIONCOMPONENT_HPP_ */
