/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4001
*/

#include <iostream>
#include "Component4001.hpp"
#include "GateNOR.hpp"

nts::Component4001::Component4001() noexcept: AComponent("4001", 14, {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    m_components.push_back(std::make_unique<GateNOR>());
    m_components.back()->setLink(1, *this, 1);
    m_components.back()->setLink(2, *this, 2);
    setLinkInternal(3, *m_components.back(), 3);

    m_components.push_back(std::make_unique<GateNOR>());
    m_components.back()->setLink(1, *this, 5);
    m_components.back()->setLink(2, *this, 6);
    setLinkInternal(4, *m_components.back(), 3);

    m_components.push_back(std::make_unique<GateNOR>());
    m_components.back()->setLink(1, *this, 8);
    m_components.back()->setLink(2, *this, 9);
    setLinkInternal(10, *m_components.back(), 3);

    m_components.push_back(std::make_unique<GateNOR>());
    m_components.back()->setLink(1, *this, 12);
    m_components.back()->setLink(2, *this, 13);
    setLinkInternal(11, *m_components.back(), 3);
}

nts::Component4001::~Component4001() noexcept
{
}

void nts::Component4001::simulate(std::size_t tick)
{
    for (const auto &component : m_components)
        component->simulate(tick);
}

void nts::Component4001::dumpInternalComponents() const
{
    std::cout << "Internal components:" << std::endl;
    for (const auto &component : m_components)
        component->dump();
}
