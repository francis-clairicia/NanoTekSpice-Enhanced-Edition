/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AComponent
*/

#include <algorithm>
#include <iostream>
#include "AComponent.hpp"
#include "BadPinException.hpp"

nts::AComponent::AComponent(const std::string &type, std::size_t nb_pins, const pin_list_t &input_pins, const pin_list_t &output_pins) noexcept:
    m_type{type}, m_internal_links{nb_pins}, m_external_links{nb_pins}, m_components{}, m_input_pins{input_pins}, m_output_pins{output_pins}
{
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(m_type, pin);
    if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
        component_link_t pair = m_external_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    if (std::find(m_output_pins.begin(), m_output_pins.end(), pin) != m_output_pins.end()) {
        component_link_t pair = m_internal_links.at(pin - 1);
        return (pair.first) ? pair.first->compute(pair.second) : nts::UNDEFINED;
    }
    return nts::UNDEFINED;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_external_links.size())
        throw BadPinException(m_type, pin);
    m_external_links[pin - 1] = std::make_pair(&other, otherPin);
}

void nts::AComponent::dump() const
{
    dumpExternalLinks();
    dumpInternalLinks();
}

void nts::AComponent::setLinkInternal(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin == 0 || pin > m_internal_links.size())
        throw BadPinException(m_type, pin);
    m_internal_links[pin - 1] = std::make_pair(&other, otherPin);
}

void nts::AComponent::dumpExternalLinks() const
{
    std::cout << m_type << " component:" << std::endl;

    std::size_t index = 0;
    for (const auto &pair : m_external_links) {
        std::cout << "-> Pin " << ++index << ": ";
        if (pair.first) {
            std::cout << "linked to pin " << pair.second << " of a component";
        } else {
            std::cout << "not linked";
        }
        std::cout << std::endl;
    }
}

void nts::AComponent::dumpInternalLinks() const
{
    std::cout << "Internal components:" << std::endl;
    for (const auto &component : m_components)
        component->dump();
    std::cout << "Internal linkage:" << std::endl;

    std::size_t index = 0;
    for (const auto &pair : m_internal_links) {
        ++index;
        if (pair.first) {
            std::cout << "-> Pin " << index << ": " << "linked to pin " << pair.second << " of a component" << std::endl;
        }
    }
}
