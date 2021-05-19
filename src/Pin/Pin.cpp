/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Pin
*/

#include <algorithm>
#include <iostream>
#include "Pin.hpp"

namespace nts
{
    Pin::Pin(Pin::Direction direction, Pin::Mode mode) noexcept:
        m_mode{direction | mode},
        m_internal_links{},
        m_external_links{}
    {
    }

    void Pin::setLinkWithExternalComponent(IComponent &component, std::size_t pin) noexcept
    {
        const auto &search = std::find_if(m_external_links.begin(), m_external_links.end(),
                                        [&component, &pin](const Pin::Link &link){return &link.component == &component && link.pin == pin;});

        if (search != m_external_links.end())
            return;

        m_external_links.push_back(Pin::Link{.component = component, .pin = pin});
        if (isInput() || isBidirectional()) {
            for (Pin::Link &link : m_internal_links) {
                link.component.setLink(link.pin, component, pin);
            }
        }
    }

    void Pin::setLinkWithInternalComponent(IComponent &component, std::size_t pin) noexcept
    {
        const auto &search = std::find_if(m_internal_links.begin(), m_internal_links.end(),
                                        [&component, &pin](const Pin::Link &link){return &link.component == &component && link.pin == pin;});

        if (search != m_internal_links.end())
            return;

        m_internal_links.push_back(Pin::Link{.component = component, .pin = pin});
        if (isInput() || isBidirectional()) {
            for (Pin::Link &link : m_external_links) {
                component.setLink(pin, link.component, link.pin);
            }
        }
    }

    Tristate Pin::compute(std::size_t tick) const
    {
        if (m_mode & OUTPUT)
            return computeLinks(m_internal_links, tick);
        if (m_mode & INPUT)
            return computeLinks(m_external_links, tick);
        return UNDEFINED;
    }

    void Pin::computeAsInput() noexcept
    {
        if (m_mode & BIDIRECTIONAL)
            m_mode = BIDIRECTIONAL | INPUT;
    }

    void Pin::computeAsOutput() noexcept
    {
        if (m_mode & BIDIRECTIONAL)
            m_mode = BIDIRECTIONAL | OUTPUT;
    }

    Tristate Pin::computeLinks(const Pin::Links &used_links, std::size_t tick) const
    {
        std::vector<Tristate> inputs;

        std::transform(used_links.begin(), used_links.end(), std::back_inserter(inputs),
                        [&tick](const Pin::Link &link){
                            link.component.simulate(tick);
                            return link.component.compute(link.pin);
                        });

        if (std::any_of(inputs.begin(), inputs.end(), [](Tristate value){return value == UNDEFINED;}))
            return UNDEFINED;

        bool output = false;
        std::for_each(inputs.begin(), inputs.end(), [&output](Tristate value){output |= value;});
        return static_cast<Tristate>(output);
    }

    bool Pin::isInput() const noexcept
    {
        return (m_mode & INPUT);
    }

    bool Pin::isOutput() const noexcept
    {
        return (m_mode & OUTPUT);
    }

    bool Pin::isBidirectional() const noexcept
    {
        return (m_mode & BIDIRECTIONAL);
    }

    void Pin::dump() const noexcept
    {
        const std::size_t space_indent = 4;

        if (m_external_links.empty()) {
            std::cout << std::string(space_indent, ' ') << "not linked" << '\n';
        } else {
            for (const Pin::Link &link : m_external_links) {
                std::cout << std::string(space_indent, ' ') << "linked to the pin " << link.pin << " of a component" << '\n';
            }
        }
    }
} // namespace nts
