/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4071
*/

#include <iostream>
#include "Component4071.hpp"
#include "GateOR.hpp"

nts::Component4071::Component4071() noexcept: AComponent("4071", 14, {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    m_components.push_back(std::make_unique<GateOR>());
    m_components.back()->setLink(GateOR::INPUT1, *this, 1);
    m_components.back()->setLink(GateOR::INPUT2, *this, 2);
    setLinkInternal(3, *m_components.back(), GateOR::OUTPUT);

    m_components.push_back(std::make_unique<GateOR>());
    m_components.back()->setLink(GateOR::INPUT1, *this, 5);
    m_components.back()->setLink(GateOR::INPUT2, *this, 6);
    setLinkInternal(4, *m_components.back(), GateOR::OUTPUT);

    m_components.push_back(std::make_unique<GateOR>());
    m_components.back()->setLink(GateOR::INPUT1, *this, 8);
    m_components.back()->setLink(GateOR::INPUT2, *this, 9);
    setLinkInternal(10, *m_components.back(), GateOR::OUTPUT);

    m_components.push_back(std::make_unique<GateOR>());
    m_components.back()->setLink(GateOR::INPUT1, *this, 12);
    m_components.back()->setLink(GateOR::INPUT2, *this, 13);
    setLinkInternal(11, *m_components.back(), GateOR::OUTPUT);
}

nts::Component4071::~Component4071() noexcept
{
}

void nts::Component4071::simulate(std::size_t tick)
{
    for (const auto &component : m_components)
        component->simulate(tick);
}

void nts::Component4071::dumpInternalComponents() const
{
    std::cout << "Internal components:" << std::endl;
    for (const auto &component : m_components)
        component->dump();
}
