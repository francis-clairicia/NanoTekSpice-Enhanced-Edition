/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SumComponent
*/

#include <iostream>
#include "SumComponent.hpp"
#include "GateAND.hpp"
#include "GateOR.hpp"
#include "GateXOR.hpp"

/*
Inputs:
    Pin 1: input Ai
    Pin 2: input Bi
    Pin 3: input Ci

Outputs:
    Pin 4: output Co
    Pin 5: output Si
*/

nts::SumComponent::SumComponent() noexcept:
    AComponent("SUM", 5, {1, 2, 3}, {4, 5}),
    m_xor1(std::make_unique<GateXOR>()),
    m_xor2(std::make_unique<GateXOR>()),
    m_and1(std::make_unique<GateAND>()),
    m_and2(std::make_unique<GateAND>()),
    m_or(std::make_unique<GateOR>())
{
    m_xor1->setLink(1, *this, 1);
    m_xor1->setLink(2, *this, 2);

    m_xor2->setLink(1, *m_xor1, 3);
    m_xor2->setLink(2, *this, 3);
    setLinkInternal(5, *m_xor2, 3);

    m_and1->setLink(1, *m_xor1, 3);
    m_and1->setLink(2, *this, 3);

    m_and2->setLink(1, *this, 1);
    m_and2->setLink(2, *this, 2);

    m_or->setLink(1, *m_and1, 3);
    m_or->setLink(2, *m_and2, 3);
    setLinkInternal(4, *m_or, 3);
}

nts::SumComponent::~SumComponent()
{
}

void nts::SumComponent::simulate(std::size_t tick)
{
    m_xor1->simulate(tick);
    m_xor2->simulate(tick);
    m_and1->simulate(tick);
    m_and2->simulate(tick);
    m_or->simulate(tick);
}

void nts::SumComponent::dumpInternalComponents() const
{
    std::cout << "Internal components:" << std::endl;
    m_xor1->dump();
    m_xor2->dump();
    m_and1->dump();
    m_and2->dump();
    m_or->dump();
}
