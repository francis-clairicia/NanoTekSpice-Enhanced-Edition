/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** TwoBitsSubComponent
*/

#include <iostream>
#include "TwoBitsSubComponent.hpp"
#include "GateAND.hpp"
#include "GateOR.hpp"
#include "GateXOR.hpp"
#include "GateNOT.hpp"

namespace nts
{
    TwoBitsSubComponent::TwoBitsSubComponent():
        BoxComponent{ComponentType::ThirdParty, 5, {Xi, Yi, Bi}, {Bo, Diff}},
        m_xor1(std::make_unique<GateXOR>()),
        m_xor2(std::make_unique<GateXOR>()),
        m_not1(std::make_unique<GateNOT>()),
        m_not2(std::make_unique<GateNOT>()),
        m_and1(std::make_unique<GateAND>()),
        m_and2(std::make_unique<GateAND>()),
        m_or(std::make_unique<GateOR>())
    {
        setLinkInternal(Xi, *m_xor1, GateXOR::INPUT1);
        setLinkInternal(Yi, *m_xor1, GateXOR::INPUT2);

        m_xor2->setLink(GateXOR::INPUT1, *m_xor1, GateXOR::OUTPUT);
        setLinkInternal(Bi, *m_xor2, GateXOR::INPUT2);
        setLinkInternal(Diff, *m_xor2, GateXOR::OUTPUT);

        m_not1->setLink(GateNOT::INPUT, *m_xor1, GateXOR::OUTPUT);
        m_and1->setLink(GateAND::INPUT1, *m_not1, GateNOT::OUTPUT);
        setLinkInternal(Bi, *m_and1, GateAND::INPUT2);

        setLinkInternal(Xi, *m_not2, GateNOT::INPUT);
        m_and2->setLink(GateAND::INPUT1, *m_not2, GateNOT::OUTPUT);
        setLinkInternal(Yi, *m_and2, GateAND::INPUT2);

        m_or->setLink(GateOR::INPUT1, *m_and1, GateAND::OUTPUT);
        m_or->setLink(GateOR::INPUT2, *m_and2, GateAND::OUTPUT);
        setLinkInternal(Bo, *m_or, GateOR::OUTPUT);
    }

    void TwoBitsSubComponent::dumpInternalComponents() const noexcept
    {
        std::cout << "Internal components:" << '\n';
        m_xor1->dump();
        m_xor2->dump();
        m_not1->dump();
        m_not2->dump();
        m_and1->dump();
        m_and2->dump();
        m_or->dump();
    }
} // namespace nts

