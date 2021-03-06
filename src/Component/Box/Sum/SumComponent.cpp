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
    BoxComponent(ComponentType::Sum, 5, {Ai, Bi, Ci}, {Co, Si}),
    m_xor1(std::make_unique<GateXOR>()),
    m_xor2(std::make_unique<GateXOR>()),
    m_and1(std::make_unique<GateAND>()),
    m_and2(std::make_unique<GateAND>()),
    m_or(std::make_unique<GateOR>())
{
    m_xor1->setLink(GateXOR::INPUT1, *this, SumComponent::Ai);
    m_xor1->setLink(GateXOR::INPUT2, *this, SumComponent::Bi);

    m_xor2->setLink(GateXOR::INPUT1, *m_xor1, GateXOR::OUTPUT);
    m_xor2->setLink(GateXOR::INPUT2, *this, SumComponent::Ci);
    setLinkInternal(SumComponent::Si, *m_xor2, GateXOR::OUTPUT);

    m_and1->setLink(GateAND::INPUT1, *m_xor1, GateXOR::OUTPUT);
    m_and1->setLink(GateAND::INPUT2, *this, SumComponent::Ci);

    m_and2->setLink(GateAND::INPUT1, *this, SumComponent::Ai);
    m_and2->setLink(GateAND::INPUT2, *this, SumComponent::Bi);

    m_or->setLink(GateOR::INPUT1, *m_and1, GateAND::OUTPUT);
    m_or->setLink(GateOR::INPUT2, *m_and2, GateAND::OUTPUT);
    setLinkInternal(SumComponent::Co, *m_or, GateOR::OUTPUT);
}

nts::SumComponent::~SumComponent() noexcept
{
}

void nts::SumComponent::dumpInternalComponents() const noexcept
{
    std::cout << "Internal components:" << '\n';
    m_xor1->dump();
    m_xor2->dump();
    m_and1->dump();
    m_and2->dump();
    m_or->dump();
}
