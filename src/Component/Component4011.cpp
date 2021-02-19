/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4011
*/

#include <iostream>
#include "Component4011.hpp"
#include "GateNAND.hpp"

nts::Component4011::Component4011() noexcept: AComponent("4011", 14, {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    m_components.push_back(std::make_unique<GateNAND>());
    m_components.back()->setLink(GateNAND::INPUT1, *this, 1);
    m_components.back()->setLink(GateNAND::INPUT2, *this, 2);
    setLinkInternal(3, *m_components.back(), GateNAND::OUTPUT);

    m_components.push_back(std::make_unique<GateNAND>());
    m_components.back()->setLink(GateNAND::INPUT1, *this, 5);
    m_components.back()->setLink(GateNAND::INPUT2, *this, 6);
    setLinkInternal(4, *m_components.back(), GateNAND::OUTPUT);

    m_components.push_back(std::make_unique<GateNAND>());
    m_components.back()->setLink(GateNAND::INPUT1, *this, 8);
    m_components.back()->setLink(GateNAND::INPUT2, *this, 9);
    setLinkInternal(10, *m_components.back(), GateNAND::OUTPUT);

    m_components.push_back(std::make_unique<GateNAND>());
    m_components.back()->setLink(GateNAND::INPUT1, *this, 12);
    m_components.back()->setLink(GateNAND::INPUT2, *this, 13);
    setLinkInternal(11, *m_components.back(), GateNAND::OUTPUT);
}

nts::Component4011::~Component4011() noexcept
{
}

void nts::Component4011::simulate(std::size_t tick)
{
    for (const auto &component : m_components)
        component->simulate(tick);
}

void nts::Component4011::dumpInternalComponents() const
{
    std::cout << "Internal components:" << std::endl;
    for (const auto &component : m_components)
        component->dump();
}
