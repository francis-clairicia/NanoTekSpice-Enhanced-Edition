/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Pin
*/

#include <algorithm>
#include <array>
#include <iostream>
#include "Pin.hpp"

nts::Pin::Pin() noexcept:
    m_links{}
{
}

nts::Pin::~Pin() noexcept
{
}

void nts::Pin::setLink(nts::IComponent &component, std::size_t pin)
{
    const auto &link = std::find_if(m_links.begin(), m_links.end(),
                                    [&component, &pin](const Pin::Link &link){return &link.component == &component && link.pin == pin;});

    if (link == m_links.end())
        m_links.push_back(Pin::Link{.component = component, .pin = pin});
}

nts::Tristate nts::Pin::compute(std::size_t tick) const
{
    static std::size_t indent = 0;

    indent += 4;
    if (m_links.empty())
        return nts::UNDEFINED;

    std::vector<nts::Tristate> inputs{};

    std::transform(m_links.begin(), m_links.end(), std::back_inserter(inputs),
                    [&tick](const Pin::Link &link){
                        link.component.simulate(tick);
                        return link.component.compute(link.pin);
                    });

    if (std::any_of(inputs.begin(), inputs.end(), [](nts::Tristate value){return value == nts::UNDEFINED;}))
        return nts::UNDEFINED;
    
    bool output = nts::FALSE;
    std::for_each(inputs.begin(), inputs.end(), [&output](nts::Tristate value){output |= value;});
    return static_cast<nts::Tristate>(output);
}

void nts::Pin::dump() const
{
    std::cout << std::string(4, ' ');
    if (!hasLinks()) {
        std::cout << "not linked" << '\n';
    } else {
        for (const Pin::Link &link : m_links)
            std::cout << "linked to the pin " << link.pin << " of a component" << '\n';
    }
}

bool nts::Pin::hasLinks() const noexcept
{
    return !m_links.empty();
}
