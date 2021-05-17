/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ACalculationComponent
*/

#include <iostream>
#include <algorithm>
#include "ACalculationComponent.hpp"
#include "BadPinException.hpp"

namespace nts
{
    ACalculationComponent::ACalculationComponent(ComponentType type,
                                                    std::size_t nb_pins,
                                                    PinList::Initializer input_pins,
                                                    PinList::Initializer output_pins) noexcept:
        m_type{type},
        m_pins{nb_pins, input_pins, output_pins, true},
        m_actual_tick{~0UL}
    {
        m_pins.setIOPinsAsOutput();
        for (std::size_t pin : m_pins.getOutputPins())
            m_output_pins[pin] = UNDEFINED;
    }

    void ACalculationComponent::simulate(std::size_t tick)
    {
        if (m_actual_tick != tick) {
            m_actual_tick = tick;
            computeOutputs(tick);
            m_pins.setIOPinsAsOutput();
        }
    }

    void ACalculationComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        if (!m_pins.hasPin(pin))
            throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
        m_pins[pin].setLinkWithExternalComponent(other, otherPin);
    }

    Tristate ACalculationComponent::compute(std::size_t pin)
    {
        if (!m_pins.hasPin(pin))
            throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
        if (m_pins[pin].isOutput())
            return m_output_pins.at(pin);
        if (m_pins[pin].isInput())
            return FALSE;
        return UNDEFINED;
    }

    void ACalculationComponent::dump() const noexcept
    {
        std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << '\n';
        m_pins.dump();
    }

    Tristate ACalculationComponent::computeInternalComponent(IComponent &component, std::size_t pin) const
    {
        component.simulate(m_actual_tick);
        return component.compute(pin);
    }
} // namespace nts