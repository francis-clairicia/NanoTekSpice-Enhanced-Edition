/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** FlipFlopComponent
*/

#include <iostream>
#include "FlipFlopComponent.hpp"
#include "GateTransmission.hpp"
#include "GateNOT.hpp"
#include "GateNOR.hpp"
#include "Node.hpp"

/*
Inputs:
    Pin 3: clock (cl)
    Pin 4: reset (r)
    Pin 5: data  (d)
    Pin 6: set   (s)

Outputs:
    Pin 1: q
    Pin 2: /q (not q)
*/

nts::FlipFlopComponent::FlipFlopComponent() noexcept:
    AComponent("FlipFlop", 6, {CLOCK, RESET, DATA, SET}, {Q, Qn}),
    m_tg1(std::make_unique<GateTransmission>()),
    m_tg2(std::make_unique<GateTransmission>()),
    m_tg3(std::make_unique<GateTransmission>()),
    m_tg4(std::make_unique<GateTransmission>()),
    m_not1(std::make_unique<GateNOT>()),
    m_not2(std::make_unique<GateNOT>()),
    m_nor1(std::make_unique<GateNOR>()),
    m_nor2(std::make_unique<GateNOR>()),
    m_nor3(std::make_unique<GateNOR>()),
    m_nor4(std::make_unique<GateNOR>()),
    m_node1(std::make_unique<Node>()),
    m_node2(std::make_unique<Node>())
{
    // Link transmission1 to DATA
    m_tg1->setLink(GateTransmission::INPUT, *this, DATA);
    m_tg1->setLink(GateTransmission::CONTROL, *this, CLOCK);

    // First NOR with DATA transmission and set
    m_nor1->setLink(GateNOR::INPUT1, *this, SET);
    m_nor1->setLink(GateNOR::INPUT2, *m_node1, Node::OUTPUT);

    // Node 1 Input Linkage
    m_node1->setLink(Node::INPUT1, *m_tg1, GateTransmission::OUTPUT);

    // 2nd NOR with NOR1 and RESET
    m_nor2->setLink(GateNOR::INPUT1, *m_nor1, GateNOR::OUTPUT);
    m_nor2->setLink(GateNOR::INPUT2, *this, RESET);

    // Transmission 2 between NOR2 output and node1
    m_tg2->setLink(GateTransmission::INPUT, *m_nor2, GateNOR::OUTPUT);
    m_tg2->setLink(GateTransmission::CONTROL, *this, CLOCK);
    m_node1->setLink(Node::INPUT2, *m_tg2, GateTransmission::OUTPUT);

    // Transmission 3 from NOR 2 to NOR 3
    m_tg3->setLink(GateTransmission::INPUT, *m_nor2, GateNOR::OUTPUT);
    m_tg3->setLink(GateTransmission::CONTROL, *this, CLOCK);

    // 3rd NOR with TG3 and RESET
    m_nor3->setLink(GateNOR::INPUT1, *m_tg3, GateTransmission::OUTPUT);
    m_nor3->setLink(GateNOR::INPUT2, *this, RESET);

    // 4th NOR with NOR3 and SET
    m_nor4->setLink(GateNOR::INPUT1, *this, SET);
    m_nor4->setLink(GateNOR::INPUT2, *m_nor3, GateNOR::OUTPUT);

    // Transmission 4 after NOR4
    m_tg4->setLink(GateTransmission::INPUT, *m_nor4, GateNOR::OUTPUT);
    m_tg4->setLink(GateTransmission::CONTROL, *this, CLOCK);

    // Q output
    m_node2->setLink(Node::INPUT1, *m_tg3, GateTransmission::OUTPUT);
    m_node2->setLink(Node::INPUT2, *m_tg4, GateTransmission::OUTPUT);
    // m_not1->setLink(GateNOT::INPUT, *m_node2, Node::OUTPUT);
    // setLinkInternal(Q, *m_not1, GateNOT::OUTPUT);
    setLinkInternal(Q, *m_node2, Node::OUTPUT);

    // /Q output
    // m_not2->setLink(GateNOT::INPUT, *m_nor3, GateNOR::OUTPUT);
    // setLinkInternal(Qn, *m_not2, GateNOT::OUTPUT);
    setLinkInternal(Qn, *m_nor3, GateNOR::OUTPUT);
}

nts::FlipFlopComponent::~FlipFlopComponent()
{
}

void nts::FlipFlopComponent::simulate(std::size_t tick)
{
    m_tg1->simulate(tick);
    m_tg2->simulate(tick);
    m_tg3->simulate(tick);
    m_tg4->simulate(tick);
    m_not1->simulate(tick);
    m_not2->simulate(tick);
    m_nor1->simulate(tick);
    m_nor2->simulate(tick);
    m_nor3->simulate(tick);
    m_nor4->simulate(tick);
}

void nts::FlipFlopComponent::dumpInternalComponents() const
{
    std::cout << "Internal components:" << std::endl;
    m_tg1->dump();
    m_tg2->dump();
    m_tg3->dump();
    m_tg4->dump();
    m_not1->dump();
    m_not2->dump();
    m_nor1->dump();
    m_nor2->dump();
    m_nor3->dump();
    m_nor4->dump();
}
