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
    protected:
        using OutputPins = std::unordered_map<std::size_t, Tristate>;

    public:
        ACalculationComponent(ComponentType type, std::size_t nb_pins,
                                PinList::Initializer input_pins, PinList::Initializer output_pins) noexcept;
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
        Tristate computeInternalComponent(IComponent &component, std::size_t pin) const;
        virtual void computeOutputs(std::size_t tick) = 0;

    protected:
        const ComponentType  m_type;
        OutputPins           m_output_pins;
        PinList              m_pins;

    private:
        std::size_t          m_actual_tick;
    };
}

#endif /* !ACALCULATIONCOMPONENT_HPP_ */
