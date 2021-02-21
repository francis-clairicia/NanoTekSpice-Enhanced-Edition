/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** DTypeFlipFlopWithSR
*/

#include <iostream>
#include "DTypeFlipFlopWithSR.hpp"
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

nts::DTypeFlipFlopWithSR::DTypeFlipFlopWithSR() noexcept:
    AComponent(DTypeFlipFlopWithSRType, 6, {CLOCK, RESET, DATA, SET}, {Q, Qn}),
    m_tg1(std::make_unique<GateTransmission>()),
    m_tg2(std::make_unique<GateTransmission>()),
    m_tg3(std::make_unique<GateTransmission>()),
    m_tg4(std::make_unique<GateTransmission>()),
    m_inverter_clock(std::make_unique<GateNOT>()),
    m_inverter1(std::make_unique<GateNOT>()),
    m_inverter2(std::make_unique<GateNOT>()),
    m_nor1(std::make_unique<GateNOR>()),
    m_nor2(std::make_unique<GateNOR>()),
    m_nor3(std::make_unique<GateNOR>()),
    m_nor4(std::make_unique<GateNOR>()),
    m_node1(std::make_unique<Node>()),
    m_node2(std::make_unique<Node>()),
    m_memoryQ(std::make_unique<MemoryGate>()),
    m_memoryQn(std::make_unique<MemoryGate>())
{
    // Clock inverter
    m_inverter_clock->setLink(GateNOT::INPUT, *this, CLOCK);

    // Link transmission1 to DATA
    m_tg1->setLink(GateTransmission::INPUT, *this, DATA);
    m_tg1->setLink(GateTransmission::CONTROL, *m_inverter_clock, GateNOT::OUTPUT);

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

    // Transmission 3 from NOR 1 to NOR 3
    m_tg3->setLink(GateTransmission::INPUT, *m_nor1, GateNOR::OUTPUT);
    m_tg3->setLink(GateTransmission::CONTROL, *this, CLOCK);

    // 3rd NOR with TG3 and RESET
    m_nor3->setLink(GateNOR::INPUT1, *m_tg3, GateTransmission::OUTPUT);
    m_nor3->setLink(GateNOR::INPUT2, *this, RESET);

    // 4th NOR with NOR3 and SET
    m_nor4->setLink(GateNOR::INPUT1, *this, SET);
    m_nor4->setLink(GateNOR::INPUT2, *m_nor3, GateNOR::OUTPUT);

    // Transmission 4 after NOR4
    m_tg4->setLink(GateTransmission::INPUT, *m_nor4, GateNOR::OUTPUT);
    m_tg4->setLink(GateTransmission::CONTROL, *m_inverter_clock, GateNOT::OUTPUT);

    // Q output
    m_node2->setLink(Node::INPUT1, *m_tg3, GateTransmission::OUTPUT);
    m_node2->setLink(Node::INPUT2, *m_tg4, GateTransmission::OUTPUT);
    m_inverter1->setLink(GateNOT::INPUT, *m_node2, Node::OUTPUT);
    m_memoryQ->setLink(MemoryGate::INPUT, *m_inverter1, GateNOT::OUTPUT);
    m_memoryQ->setLink(MemoryGate::CLOCK, *this, CLOCK);
    m_memoryQ->setLink(MemoryGate::RESET, *this, RESET);
    m_memoryQ->setLink(MemoryGate::SET, *this, SET);
    setLinkInternal(Q, *m_memoryQ, MemoryGate::OUTPUT);

    // /Q (Qn) output
    m_inverter2->setLink(GateNOT::INPUT, *m_nor3, GateNOR::OUTPUT);
    m_memoryQn->setLink(MemoryGate::INPUT, *m_inverter2, GateNOT::OUTPUT);
    m_memoryQn->setLink(MemoryGate::CLOCK, *this, CLOCK);
    m_memoryQn->setLink(MemoryGate::RESET, *this, RESET);
    m_memoryQn->setLink(MemoryGate::SET, *this, SET);
    setLinkInternal(Qn, *m_memoryQn, MemoryGate::OUTPUT);
}

nts::DTypeFlipFlopWithSR::~DTypeFlipFlopWithSR()
{
}

void nts::DTypeFlipFlopWithSR::simulate(std::size_t tick)
{
    m_tg1->simulate(tick);
    m_tg2->simulate(tick);
    m_tg3->simulate(tick);
    m_tg4->simulate(tick);
    m_inverter_clock->simulate(tick);
    m_inverter1->simulate(tick);
    m_inverter2->simulate(tick);
    m_nor1->simulate(tick);
    m_nor2->simulate(tick);
    m_nor3->simulate(tick);
    m_nor4->simulate(tick);
    m_node1->simulate(tick);
    m_node2->simulate(tick);
    m_memoryQ->simulate(tick);
    m_memoryQn->simulate(tick);
}

void nts::DTypeFlipFlopWithSR::dumpInternalComponents() const
{
    std::cout << "Internal components:" << std::endl;
    m_tg1->dump();
    m_tg2->dump();
    m_tg3->dump();
    m_tg4->dump();
    m_inverter_clock->dump();
    m_inverter1->dump();
    m_inverter2->dump();
    m_nor1->dump();
    m_nor2->dump();
    m_nor3->dump();
    m_nor4->dump();
}

nts::DTypeFlipFlopWithSR::MemoryGate::MemoryGate() noexcept:
    AGate(DTypeFlipFlopMemoryType, 5, {MemoryGate::INPUT, MemoryGate::CLOCK, MemoryGate::RESET, MemoryGate::SET}, MemoryGate::OUTPUT),
    m_buffer(nts::UNDEFINED)
{
}

nts::Tristate nts::DTypeFlipFlopWithSR::MemoryGate::computeOutput()
{
    nts::Tristate input = compute(MemoryGate::INPUT);
    nts::Tristate clock = compute(MemoryGate::CLOCK);
    nts::Tristate reset = compute(MemoryGate::RESET);
    nts::Tristate set = compute(MemoryGate::SET);

    if (reset == nts::UNDEFINED || set == nts::UNDEFINED || clock == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (reset == nts::TRUE || set == nts::TRUE || clock == nts::TRUE)
        m_buffer = input;
    return m_buffer;
}