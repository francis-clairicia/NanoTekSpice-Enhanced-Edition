/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ACalculationComponent
*/

#include <algorithm>
#include <iostream>
#include "ACalculationComponent.hpp"
#include "BadPinException.hpp"

nts::ACalculationComponent::ACalculationComponent(const std::string &type, std::size_t nb_pins, const pin_list_t &input_pins, const pin_list_t &output_pins) noexcept:
    AComponent(type, nb_pins, input_pins, output_pins)
{
}

nts::Tristate nts::ACalculationComponent::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        component_link_t pair = m_external_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    if (std::find(m_output_pins.begin(), m_output_pins.end(), pin) != m_output_pins.end()) {
        return computeOutput(pin);
    }
    return nts::UNDEFINED;
}

void nts::ACalculationComponent::dump() const
{
    dumpExternalLinks();
}
