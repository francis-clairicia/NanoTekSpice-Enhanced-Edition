/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4081
*/

#include "Component4081.hpp"
#include "GateAND.hpp"

nts::Component4081::Component4081() noexcept: AComponent("4081", 14, {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    m_components.push_back(std::make_unique<GateAND>());
    m_components.back()->setLink(1, *this, 1);
    m_components.back()->setLink(2, *this, 2);
    m_components.back()->setLink(3, *this, 3);
    setLinkInternal(3, *(m_components.back().get()), 3);

    m_components.push_back(std::make_unique<GateAND>());
    m_components.back()->setLink(1, *this, 5);
    m_components.back()->setLink(2, *this, 6);
    m_components.back()->setLink(3, *this, 4);
    setLinkInternal(4, *(m_components.back().get()), 3);

    m_components.push_back(std::make_unique<GateAND>());
    m_components.back()->setLink(1, *this, 8);
    m_components.back()->setLink(2, *this, 9);
    m_components.back()->setLink(3, *this, 10);
    setLinkInternal(10, *(m_components.back().get()), 3);

    m_components.push_back(std::make_unique<GateAND>());
    m_components.back()->setLink(1, *this, 12);
    m_components.back()->setLink(2, *this, 13);
    m_components.back()->setLink(3, *this, 11);
    setLinkInternal(11, *(m_components.back().get()), 3);
}

nts::Component4081::~Component4081()
{
}

void nts::Component4081::simulate(std::size_t tick __attribute__((unused)))
{
}

