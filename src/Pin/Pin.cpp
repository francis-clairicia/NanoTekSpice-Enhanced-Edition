/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Pin
*/

#include <algorithm>
#include <iostream>
#include "Pin.hpp"

nts::Pin::Pin(Pin::Mode mode) noexcept:
    m_mode{mode},
    m_internal_links{},
    m_external_links{}
{
}

void nts::Pin::setLinkWithExternalComponent(nts::IComponent &component, std::size_t pin) noexcept
{
    const auto &search = std::find_if(m_external_links.begin(), m_external_links.end(),
                                    [&component, &pin](const Pin::Link &link){return &link.component == &component && link.pin == pin;});

    if (search != m_external_links.end()) 
        return;

    m_external_links.push_back(Pin::Link{.component = component, .pin = pin});
    if (m_mode == Mode::INPUT) {
        for (Pin::Link &link : m_internal_links) {
            link.component.setLink(link.pin, component, pin);
        }
    }
}

void nts::Pin::setLinkWithInternalComponent(nts::IComponent &component, std::size_t pin) noexcept
{
    const auto &search = std::find_if(m_internal_links.begin(), m_internal_links.end(),
                                    [&component, &pin](const Pin::Link &link){return &link.component == &component && link.pin == pin;});

    if (search != m_internal_links.end()) 
        return;

    m_internal_links.push_back(Pin::Link{.component = component, .pin = pin});
    if (m_mode == Mode::INPUT) {
        for (Pin::Link &link : m_external_links) {
            component.setLink(pin, link.component, link.pin);
        }
    }
}

nts::Tristate nts::Pin::compute(std::size_t tick) const
{
    if (m_mode == Mode::NONE)
        return nts::UNDEFINED;

    const std::vector<Pin::Link> &used_links = (m_mode == Mode::INPUT) ? m_external_links : m_internal_links;

    std::vector<nts::Tristate> inputs;

    std::transform(used_links.begin(), used_links.end(), std::back_inserter(inputs),
                    [&tick](const Pin::Link &link){
                        link.component.simulate(tick);
                        return link.component.compute(link.pin);
                    });

    if (std::any_of(inputs.begin(), inputs.end(), [](nts::Tristate value){return value == nts::UNDEFINED;}))
        return nts::UNDEFINED;

    bool output = false;
    std::for_each(inputs.begin(), inputs.end(), [&output](nts::Tristate value){output |= value;});
    return static_cast<nts::Tristate>(output);
}

void nts::Pin::dump() const noexcept
{
    std::cout << std::string(4, ' ');
    if (m_external_links.empty()) {
        std::cout << "not linked" << '\n';
    } else {
        for (const Pin::Link &link : m_external_links)
            std::cout << "linked to the pin " << link.pin << " of a component" << '\n';
    }
}

nts::Pin &nts::Pin::operator=(Pin::Mode mode) noexcept
{
    m_mode = mode;
    return *this;
}

bool nts::Pin::operator==(Pin::Mode mode) const noexcept
{
    return m_mode == mode;
}

bool nts::Pin::operator!=(Pin::Mode mode) const noexcept
{
    return !(*this == mode);
}