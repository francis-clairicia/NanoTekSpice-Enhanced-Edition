/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4008
*/

#include <iostream>
#include "Component4008.hpp"
#include "SumComponent.hpp"

nts::Component4008::Component4008() noexcept: AComponent("4008", 16, {1, 2, 3, 4, 5, 6, 7, 9, 15}, {10, 11, 12, 13, 14})
{
    for (std::size_t index = 0; index < 4; ++index)
        m_components.push_back(std::make_unique<SumComponent>());

    m_components[0]->setLink(SumComponent::Ai, *this, 7);
    m_components[0]->setLink(SumComponent::Bi, *this, 6);
    m_components[0]->setLink(SumComponent::Ci, *this, 9);
    setLinkInternal(10, *(m_components[0]), SumComponent::Si);

    m_components[1]->setLink(SumComponent::Ai, *this, 5);
    m_components[1]->setLink(SumComponent::Bi, *this, 4);
    m_components[1]->setLink(SumComponent::Ci, *(m_components[0]), SumComponent::Co);
    setLinkInternal(11, *(m_components[1]), SumComponent::Si);

    m_components[2]->setLink(SumComponent::Ai, *this, 3);
    m_components[2]->setLink(SumComponent::Bi, *this, 2);
    m_components[2]->setLink(SumComponent::Ci, *(m_components[1]), SumComponent::Co);
    setLinkInternal(12, *(m_components[2]), SumComponent::Si);

    m_components[3]->setLink(SumComponent::Ai, *this, 1);
    m_components[3]->setLink(SumComponent::Bi, *this, 15);
    m_components[3]->setLink(SumComponent::Ci, *(m_components[2]), SumComponent::Co);
    setLinkInternal(13, *(m_components[3]), SumComponent::Si);
    setLinkInternal(14, *(m_components[3]), SumComponent::Co);
}

nts::Component4008::~Component4008() noexcept
{
}

void nts::Component4008::simulate(std::size_t tick)
{
    for (const auto &component : m_components)
        component->simulate(tick);
}

void nts::Component4008::dumpInternalComponents() const
{
    std::cout << "Internal components:" << std::endl;
    for (const auto &component : m_components)
        component->dump();
}
