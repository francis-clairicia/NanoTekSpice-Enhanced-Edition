/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
        auto search = std::find_if(m_external_links.begin(), m_external_links.end(),
                                    [&component, &pin](const Pin::Link &link)
                                    {
                                        return &link.component == &component && link.pin == pin;
                                    });

        if (search != m_external_links.end())
            return;

        m_external_links.emplace_back(component, pin);
        if (isInput() || isBidirectional()) {
            for (Pin::Link &link : m_internal_links) {
                link.component.setLink(link.pin, component, pin);
            }
        }
    }

    void Pin::setLinkWithInternalComponent(IComponent &component, std::size_t pin) noexcept
    {
        auto search = std::find_if(m_internal_links.begin(), m_internal_links.end(),
                                    [&component, &pin](const Pin::Link &link)
                                    {
                                        return &link.component == &component && link.pin == pin;
                                    });

        if (search != m_internal_links.end())
            return;

        m_internal_links.emplace_back(component, pin);
        if (isInput() || isBidirectional()) {
            for (Pin::Link &link : m_external_links) {
                component.setLink(pin, link.component, link.pin);
            }
        }
    }

    bool Pin::hasInternalLinks() const noexcept
    {
        return !m_internal_links.empty();
    }

    Tristate Pin::computeInternalLinks(std::size_t tick) const
    {
        return computeLinks(m_internal_links, tick);
    }

    Tristate Pin::computeExternalLinks(std::size_t tick) const
    {
        return computeLinks(m_external_links, tick);
    }
    
    void Pin::computeAsInput() noexcept
    {
        if (isBidirectional())
            m_mode = BIDIRECTIONAL | INPUT;
    }

    void Pin::computeAsOutput() noexcept
    {
        if (isBidirectional())
            m_mode = BIDIRECTIONAL | OUTPUT;
    }

    Tristate Pin::computeLinks(const Pin::Links &used_links, std::size_t tick) const
    {
        std::vector<Tristate> inputs(used_links.size());

        std::transform(used_links.begin(), used_links.end(), inputs.begin(),
                       [&tick](const Pin::Link &link)
                       {
                           link.component.simulate(tick);
                           return link.component.compute(link.pin);
                       });

        Tristate output = FALSE;
        for (Tristate value : inputs) {
            switch (value)
            {
            case TRUE:
                return TRUE;
            case UNDEFINED:
                output = UNDEFINED;
                break;
            default:
                break;
            }
        }
        return output;
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
