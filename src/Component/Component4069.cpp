/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4069
*/

#include "Component4069.hpp"
#include "GateNOT.hpp"

nts::Component4069::Component4069(): AComponent("4069", 14, {1, 3, 5, 9, 11, 13}, {2, 4, 6, 8, 10, 12})
{
    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 1);
    m_components.back()->setLink(2, *this, 2);
    setLinkInternal(2, *(m_components.back().get()), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 3);
    m_components.back()->setLink(2, *this, 4);
    setLinkInternal(4, *(m_components.back().get()), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 5);
    m_components.back()->setLink(2, *this, 6);
    setLinkInternal(6, *(m_components.back().get()), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 9);
    m_components.back()->setLink(2, *this, 8);
    setLinkInternal(8, *(m_components.back().get()), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 11);
    m_components.back()->setLink(2, *this, 10);
    setLinkInternal(10, *(m_components.back().get()), 2);

    m_components.push_back(std::make_unique<GateNOT>());
    m_components.back()->setLink(1, *this, 13);
    m_components.back()->setLink(2, *this, 12);
    setLinkInternal(12, *(m_components.back().get()), 2);
}

nts::Component4069::~Component4069()
{
}

void nts::Component4069::simulate(std::size_t tick __attribute__((unused)))
{
}

