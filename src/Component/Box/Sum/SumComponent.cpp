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

namespace nts
{
    SumComponent::SumComponent() noexcept:
        BoxComponent(ComponentType::Sum, 5, {Ai, Bi, Ci}, {Co, Si}),
        m_xor1(std::make_unique<GateXOR>()),
        m_xor2(std::make_unique<GateXOR>()),
        m_and1(std::make_unique<GateAND>()),
        m_and2(std::make_unique<GateAND>()),
        m_or(std::make_unique<GateOR>())
    {
        setLinkInternal(Ai, *m_xor1, GateXOR::INPUT1);
        setLinkInternal(Bi, *m_xor1, GateXOR::INPUT2);

        m_xor2->setLink(GateXOR::INPUT1, *m_xor1, GateXOR::OUTPUT);
        setLinkInternal(Ci, *m_xor2, GateXOR::INPUT2);
        setLinkInternal(Si, *m_xor2, GateXOR::OUTPUT);

        m_and1->setLink(GateAND::INPUT1, *m_xor1, GateXOR::OUTPUT);
        setLinkInternal(Ci, *m_and1, GateAND::INPUT2);

        setLinkInternal(Ai, *m_and2, GateAND::INPUT1);
        setLinkInternal(Bi, *m_and2, GateAND::INPUT2);

        m_or->setLink(GateOR::INPUT1, *m_and1, GateAND::OUTPUT);
        m_or->setLink(GateOR::INPUT2, *m_and2, GateAND::OUTPUT);
        setLinkInternal(Co, *m_or, GateOR::OUTPUT);
    }

    void SumComponent::dumpInternalComponents() const noexcept
    {
        std::cout << "Internal components:" << '\n';
        m_xor1->dump();
        m_xor2->dump();
        m_and1->dump();
        m_and2->dump();
        m_or->dump();
    }
} // namespace nts