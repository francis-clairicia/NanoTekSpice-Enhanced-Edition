/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4030
*/

#include "Component4030.hpp"
#include "GateXOR.hpp"

nts::Component4030::Component4030(): AComponent("4030", 14, {1, 2, 5, 6, 8, 9, 12, 13}, {3, 4, 10, 11})
{
    m_components.push_back(std::make_unique<GateXOR>());
    m_components.back()->setLink(1, *this, 1);
    m_components.back()->setLink(2, *this, 2);
    m_components.back()->setLink(3, *this, 3);
    setLinkInternal(3, *m_components.back(), 3);

    m_components.push_back(std::make_unique<GateXOR>());
    m_components.back()->setLink(1, *this, 5);
    m_components.back()->setLink(2, *this, 6);
    m_components.back()->setLink(3, *this, 4);
    setLinkInternal(4, *m_components.back(), 3);

    m_components.push_back(std::make_unique<GateXOR>());
    m_components.back()->setLink(1, *this, 8);
    m_components.back()->setLink(2, *this, 9);
    m_components.back()->setLink(3, *this, 10);
    setLinkInternal(10, *m_components.back(), 3);

    m_components.push_back(std::make_unique<GateXOR>());
    m_components.back()->setLink(1, *this, 12);
    m_components.back()->setLink(2, *this, 13);
    m_components.back()->setLink(3, *this, 11);
    setLinkInternal(11, *m_components.back(), 3);
}

nts::Component4030::~Component4030()
{
}

void nts::Component4030::simulate(std::size_t tick __attribute__((unused)))
{
}

