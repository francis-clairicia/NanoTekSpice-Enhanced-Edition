/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4013
*/

#include <iostream>
#include "Component4013.hpp"
#include "FlipFlopComponent.hpp"

nts::Component4013::Component4013() noexcept: AComponent("4013", 14, {3, 4, 5, 6, 8, 9, 10, 11}, {1, 2, 12, 13})
{
    m_components.push_back(std::make_unique<FlipFlopComponent>());
    m_components.back()->setLink(FlipFlopComponent::CLOCK, *this, 3);
    m_components.back()->setLink(FlipFlopComponent::RESET, *this, 4);
    m_components.back()->setLink(FlipFlopComponent::DATA, *this, 5);
    m_components.back()->setLink(FlipFlopComponent::SET, *this, 6);
    setLinkInternal(1, *m_components.back(), FlipFlopComponent::Q);
    setLinkInternal(2, *m_components.back(), FlipFlopComponent::Qn);

    m_components.push_back(std::make_unique<FlipFlopComponent>());
    m_components.back()->setLink(FlipFlopComponent::CLOCK, *this, 11);
    m_components.back()->setLink(FlipFlopComponent::RESET, *this, 10);
    m_components.back()->setLink(FlipFlopComponent::DATA, *this, 9);
    m_components.back()->setLink(FlipFlopComponent::SET, *this, 8);
    setLinkInternal(13, *m_components.back(), FlipFlopComponent::Q);
    setLinkInternal(12, *m_components.back(), FlipFlopComponent::Qn);
}

nts::Component4013::~Component4013() noexcept
{
}

void nts::Component4013::simulate(std::size_t tick)
{
    for (const auto &component : m_components)
        component->simulate(tick);
}

void nts::Component4013::dumpInternalComponents() const
{
    std::cout << "Internal components:" << std::endl;
    for (const auto &component : m_components)
        component->dump();
}
