/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4013
*/

#include <iostream>
#include "Component4013.hpp"
#include "DTypeFlipFlopWithSR.hpp"

nts::Component4013::Component4013() noexcept:
    BoxComponent(ComponentType::C4013, 14, {
        CLOCK1, RESET1, DATA1, SET1, CLOCK2, RESET2, DATA2, SET2
    }, {
        Q1, Q1n, Q2, Q2n
    })
{
    m_components.push_back(std::make_unique<DTypeFlipFlopWithSR>());
    m_components.back()->setLink(DTypeFlipFlopWithSR::CLOCK, *this, CLOCK1);
    m_components.back()->setLink(DTypeFlipFlopWithSR::RESET, *this, RESET1);
    m_components.back()->setLink(DTypeFlipFlopWithSR::DATA, *this, DATA1);
    m_components.back()->setLink(DTypeFlipFlopWithSR::SET, *this, SET1);
    setLinkInternal(Q1, *m_components.back(), DTypeFlipFlopWithSR::Q);
    setLinkInternal(Q1n, *m_components.back(), DTypeFlipFlopWithSR::Qn);

    m_components.push_back(std::make_unique<DTypeFlipFlopWithSR>());
    m_components.back()->setLink(DTypeFlipFlopWithSR::CLOCK, *this, CLOCK2);
    m_components.back()->setLink(DTypeFlipFlopWithSR::RESET, *this, RESET2);
    m_components.back()->setLink(DTypeFlipFlopWithSR::DATA, *this, DATA2);
    m_components.back()->setLink(DTypeFlipFlopWithSR::SET, *this, SET2);
    setLinkInternal(Q2, *m_components.back(), DTypeFlipFlopWithSR::Q);
    setLinkInternal(Q2n, *m_components.back(), DTypeFlipFlopWithSR::Qn);
}

nts::Component4013::~Component4013() noexcept
{
}

void nts::Component4013::dumpInternalComponents() const
{
    std::cout << "Internal components:" << '\n';
    for (const auto &component : m_components)
        component->dump();
}
