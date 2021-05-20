/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ACalculationComponent
*/

#include <iostream>
#include <algorithm>
#include "ACalculationComponent.hpp"
#include "constants.hpp"

namespace nts
{
    ACalculationComponent::ACalculationComponent(ComponentType type,
                                                 std::size_t nb_pins,
                                                 PinList::Initializer input_pins,
                                                 PinList::Initializer output_pins) noexcept:
        m_type{type},
        m_pins{type, nb_pins, input_pins, output_pins, true}
    {
    }

    void ACalculationComponent::simulate(std::size_t tick)
    {
        m_pins.simulate(tick, &ACalculationComponent::computeOutputs, this);
    }

    void ACalculationComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        m_pins.setLink(pin, other, otherPin);
    }

    Tristate ACalculationComponent::compute(std::size_t pin)
    {
        return m_pins.compute(pin);
    }

    void ACalculationComponent::dump() const noexcept
    {
        std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " component:" << '\n';
        m_pins.dump();
    }
} // namespace nts