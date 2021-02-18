/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4013
*/

#include "Component4013.hpp"
#include "FlipFlopComponent.hpp"

nts::Component4013::Component4013() noexcept: AComponent("4013", 14, {3, 4, 5, 6, 8, 9, 10, 11}, {1, 2, 12, 13})
{
    m_components.push_back(std::make_unique<FlipFlopComponent>());
    m_components.back()->setLink(1, *this, 1);
    m_components.back()->setLink(2, *this, 2);
    m_components.back()->setLink(3, *this, 3);
    m_components.back()->setLink(4, *this, 4);
    m_components.back()->setLink(5, *this, 5);
    m_components.back()->setLink(6, *this, 6);
    setLinkInternal(1, *m_components.back(), 1);
    setLinkInternal(2, *m_components.back(), 2);

    m_components.push_back(std::make_unique<FlipFlopComponent>());
    m_components.back()->setLink(1, *this, 13);
    m_components.back()->setLink(2, *this, 12);
    m_components.back()->setLink(3, *this, 11);
    m_components.back()->setLink(4, *this, 10);
    m_components.back()->setLink(5, *this, 9);
    m_components.back()->setLink(6, *this, 8);
    setLinkInternal(12, *m_components.back(), 2);
    setLinkInternal(13, *m_components.back(), 1);
}

nts::Component4013::~Component4013() noexcept
{
}

void nts::Component4013::simulate(std::size_t tick __attribute__((unused)))
{
}

