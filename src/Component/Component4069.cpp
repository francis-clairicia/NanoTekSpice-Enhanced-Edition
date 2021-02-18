/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4069
*/

#include <iostream>
#include "Component4069.hpp"
#include "GateNOT.hpp"

nts::Component4069::Component4069() noexcept: AComponent("4069", 14, {1, 3, 5, 9, 11, 13}, {2, 4, 6, 8, 10, 12})
{
    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 1);
    setLinkInternal(2, *m_components.back(), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 3);
    setLinkInternal(4, *m_components.back(), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 5);
    setLinkInternal(6, *m_components.back(), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 9);
    setLinkInternal(8, *m_components.back(), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 11);
    setLinkInternal(10, *m_components.back(), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 13);
    setLinkInternal(12, *m_components.back(), 2);
}

nts::Component4069::~Component4069() noexcept
{
}

void nts::Component4069::simulate(std::size_t tick __attribute__((unused)))
{
}

void nts::Component4069::dumpInternalComponents() const
{
    std::cout << "Internal components:" << std::endl;
    for (const auto &component : m_components)
        component->dump();
}
