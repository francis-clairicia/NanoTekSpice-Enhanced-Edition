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
    class ACalculationComponent: public IComponent
    {
    public:
        ACalculationComponent(ComponentType type, std::size_t nb_pins, PinList::Initializer input_pins, PinList::Initializer output_pins) noexcept;
        ACalculationComponent(const ACalculationComponent &other) noexcept = delete;
        ACalculationComponent(ACalculationComponent &&other) noexcept = default;
        ~ACalculationComponent() noexcept override = default;

        void simulate(std::size_t tick) final;
        Tristate compute(std::size_t pin) final;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) final;
        void dump() const noexcept final;

        ACalculationComponent &operator=(const ACalculationComponent &rhs) noexcept = delete;
        ACalculationComponent &operator=(ACalculationComponent &&rhs) noexcept = default;

    protected:
        virtual void computeOutputs() = 0;

    protected:
        const ComponentType  m_type;
        PinList              m_pins;
    };
}

#endif /* !ACALCULATIONCOMPONENT_HPP_ */
