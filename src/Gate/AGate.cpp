/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AGate
*/

#include <algorithm>
#include <iostream>
#include "AGate.hpp"
#include "BadPinException.hpp"

nts::AGate::AGate(nts::ComponentType type, std::size_t nb_pins, const pinList_t &input_pins, const pinList_t &output_pins) noexcept:
    m_value{}, m_type(type), m_computed(false), m_actual_tick(0), m_computed_pins{},
    m_links{nb_pins}, m_input_pins{input_pins}, m_output_pins{output_pins}
{
    for (std::size_t pin : output_pins)
        m_value[pin] = nts::UNDEFINED;
}

void nts::AGate::simulate(std::size_t tick)
{
    if (isNextTick(tick)) {
        m_computed_pins.clear();
        m_actual_tick = tick;
        m_computed = false;
    }
}

void nts::AGate::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    m_links[pin - 1].component = &other;
    m_links[pin - 1].pin = otherPin;
}

nts::Tristate nts::AGate::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_links.size())
        throw BadPinException(COMPONENT_TYPE_AS_STRING.at(m_type), pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        const Link &link = m_links.at(pin - 1);
        return (link.component) ? link.component->compute(link.pin) : nts::UNDEFINED;
    }
    if (std::find(m_output_pins.begin(), m_output_pins.end(), pin) != m_output_pins.end()) {
        if (std::find(m_computed_pins.begin(), m_computed_pins.end(), pin) == m_computed_pins.end()) {
            m_computed_pins.push_back(pin);
            m_value[pin] = computeOutput(pin);
        }
        return m_value.at(pin);
    }
    return nts::UNDEFINED;
}

void nts::AGate::dump() const
{
    std::cout << COMPONENT_TYPE_AS_STRING.at(m_type) << " gate component:" << std::endl;

    std::size_t index = 0;
    for (const auto &link : m_links) {
        std::cout << "-> Pin " << index << ": ";
        if (std::find(m_output_pins.begin(), m_output_pins.end(), ++index) == m_output_pins.end()) {
            if (link.component) {
                std::cout << "linked to pin " << link.pin << " of a component";
            } else {
                std::cout << "not linked";
            }
        } else {
            std::cout << "Output pin";
        }
        std::cout << std::endl;
    }
}

bool nts::AGate::isNextTick(std::size_t tick) const
{
    return m_actual_tick < tick;
}
