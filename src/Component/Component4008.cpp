/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4008
*/

#include <iostream>
#include "Component4008.hpp"
#include "SumComponent.hpp"

nts::Component4008::Component4008() noexcept:
    AComponent(Component4008Type, 16, {
        A1, B1, A2, B2, A3, B3, A4, B4, Cin
    }, {
        S1, S2, S3, S4, Cout
    })
{
    for (std::size_t index = 0; index < 4; ++index)
        m_components.push_back(std::make_unique<SumComponent>());

    m_components[0]->setLink(SumComponent::Ai, *this, A1);
    m_components[0]->setLink(SumComponent::Bi, *this, B1);
    m_components[0]->setLink(SumComponent::Ci, *this, Cin);
    setLinkInternal(S1, *(m_components[0]), SumComponent::Si);

    m_components[1]->setLink(SumComponent::Ai, *this, A2);
    m_components[1]->setLink(SumComponent::Bi, *this, B2);
    m_components[1]->setLink(SumComponent::Ci, *(m_components[0]), SumComponent::Co);
    setLinkInternal(S2, *(m_components[1]), SumComponent::Si);

    m_components[2]->setLink(SumComponent::Ai, *this, A3);
    m_components[2]->setLink(SumComponent::Bi, *this, B3);
    m_components[2]->setLink(SumComponent::Ci, *(m_components[1]), SumComponent::Co);
    setLinkInternal(S3, *(m_components[2]), SumComponent::Si);

    m_components[3]->setLink(SumComponent::Ai, *this, A4);
    m_components[3]->setLink(SumComponent::Bi, *this, B4);
    m_components[3]->setLink(SumComponent::Ci, *(m_components[2]), SumComponent::Co);
    setLinkInternal(S4, *(m_components[3]), SumComponent::Si);
    setLinkInternal(Cout, *(m_components[3]), SumComponent::Co);
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
