/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4017
*/

#include "Component4017.hpp"
#include "GateAND.hpp"
#include "GateOR.hpp"
#include "GateNOT.hpp"
#include "GateNOR.hpp"
#include "ConstComponent.hpp"
#include "DTypeFlipFlopWithSR.hpp"

nts::Component4017::Component4017() noexcept:
    AComponent(Component4017Type, 16, {CP0, CP1, MR}, {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q5_9}),
    m_ground(std::make_unique<FalseComponent>()),
    m_inverter_cp1(std::make_unique<GateNOT>()),
    m_and_gate_clock(std::make_unique<GateAND>()),
    m_and_gate_data(std::make_unique<GateAND>()),
    m_or_gate_data(std::make_unique<GateOR>())
{
    for (std::size_t index = 0; index < 10; ++index)
        m_nor.push_back(std::make_unique<GateNOR>());
    for (std::size_t index = 0; index < 5; ++index)
        m_flipflops.push_back(std::make_unique<DTypeFlipFlopWithSR>());

    m_inverter_cp1->setLink(GateNOT::INPUT, *this, CP1);
    m_and_gate_clock->setLink(GateAND::INPUT1, *m_inverter_cp1, GateNOT::OUTPUT);
    m_and_gate_clock->setLink(GateAND::INPUT2, *this, CP0);

    for (auto &flipflop : m_flipflops) {
        flipflop->setLink(DTypeFlipFlopWithSR::CLOCK, *m_and_gate_clock, GateAND::OUTPUT);
        flipflop->setLink(DTypeFlipFlopWithSR::RESET, *this, MR);
        flipflop->setLink(DTypeFlipFlopWithSR::SET, *m_ground, FalseComponent::OUTPUT);
    }

    m_flipflops[0]->setLink(DTypeFlipFlopWithSR::DATA, *m_flipflops.back(), DTypeFlipFlopWithSR::Qn);
    m_flipflops[1]->setLink(DTypeFlipFlopWithSR::DATA, *m_flipflops[0], DTypeFlipFlopWithSR::Q);

    m_or_gate_data->setLink(GateOR::INPUT1, *m_flipflops[2], DTypeFlipFlopWithSR::Q);
    m_or_gate_data->setLink(GateOR::INPUT2, *m_flipflops[0], DTypeFlipFlopWithSR::Q);
    m_and_gate_data->setLink(GateAND::INPUT1, *m_or_gate_data, GateOR::OUTPUT);
    m_and_gate_data->setLink(GateAND::INPUT2, *m_flipflops[1], DTypeFlipFlopWithSR::Q);

    m_flipflops[2]->setLink(DTypeFlipFlopWithSR::DATA, *m_and_gate_data, GateAND::OUTPUT);
    m_flipflops[3]->setLink(DTypeFlipFlopWithSR::DATA, *m_flipflops[2], DTypeFlipFlopWithSR::Q);
    m_flipflops[4]->setLink(DTypeFlipFlopWithSR::DATA, *m_flipflops[3], DTypeFlipFlopWithSR::Q);

    m_nor[0]->setLink(GateNOR::INPUT1, *m_flipflops[4], DTypeFlipFlopWithSR::Q);
    m_nor[0]->setLink(GateNOR::INPUT2, *m_flipflops[0], DTypeFlipFlopWithSR::Q);

    m_nor[1]->setLink(GateNOR::INPUT1, *m_flipflops[1], DTypeFlipFlopWithSR::Q);
    m_nor[1]->setLink(GateNOR::INPUT2, *m_flipflops[0], DTypeFlipFlopWithSR::Qn);

    m_nor[2]->setLink(GateNOR::INPUT1, *m_flipflops[1], DTypeFlipFlopWithSR::Qn);
    m_nor[2]->setLink(GateNOR::INPUT2, *m_flipflops[2], DTypeFlipFlopWithSR::Q);

    m_nor[3]->setLink(GateNOR::INPUT1, *m_flipflops[3], DTypeFlipFlopWithSR::Q);
    m_nor[3]->setLink(GateNOR::INPUT2, *m_flipflops[2], DTypeFlipFlopWithSR::Qn);

    m_nor[4]->setLink(GateNOR::INPUT1, *m_flipflops[4], DTypeFlipFlopWithSR::Q);
    m_nor[4]->setLink(GateNOR::INPUT2, *m_flipflops[3], DTypeFlipFlopWithSR::Qn);

    m_nor[5]->setLink(GateNOR::INPUT1, *m_flipflops[0], DTypeFlipFlopWithSR::Qn);
    m_nor[5]->setLink(GateNOR::INPUT2, *m_flipflops[4], DTypeFlipFlopWithSR::Qn);

    m_nor[6]->setLink(GateNOR::INPUT1, *m_flipflops[0], DTypeFlipFlopWithSR::Q);
    m_nor[6]->setLink(GateNOR::INPUT2, *m_flipflops[1], DTypeFlipFlopWithSR::Qn);

    m_nor[7]->setLink(GateNOR::INPUT1, *m_flipflops[1], DTypeFlipFlopWithSR::Q);
    m_nor[7]->setLink(GateNOR::INPUT2, *m_flipflops[2], DTypeFlipFlopWithSR::Qn);

    m_nor[8]->setLink(GateNOR::INPUT1, *m_flipflops[3], DTypeFlipFlopWithSR::Qn);
    m_nor[8]->setLink(GateNOR::INPUT2, *m_flipflops[2], DTypeFlipFlopWithSR::Q);

    m_nor[9]->setLink(GateNOR::INPUT1, *m_flipflops[3], DTypeFlipFlopWithSR::Q);
    m_nor[9]->setLink(GateNOR::INPUT2, *m_flipflops[4], DTypeFlipFlopWithSR::Qn);

    for (std::size_t index = 0; index < m_nor.size(); ++index)
        setLinkInternal(m_output_pins[index], *m_nor[index], GateNOR::OUTPUT);
    setLinkInternal(Q5_9, *m_flipflops[4], DTypeFlipFlopWithSR::Qn);
}

nts::Component4017::~Component4017() noexcept
{
}

void nts::Component4017::simulate(std::size_t tick)
{
    m_inverter_cp1->simulate(tick);
    m_and_gate_clock->simulate(tick);
    m_and_gate_data->simulate(tick);
    m_or_gate_data->simulate(tick);
    for (auto &nor : m_nor)
        nor->simulate(tick);
    for (auto &flipflop : m_flipflops)
        flipflop->simulate(tick);
}

void nts::Component4017::dumpInternalComponents() const
{
    m_inverter_cp1->dump();
    m_and_gate_clock->dump();
    m_and_gate_data->dump();
    m_or_gate_data->dump();
    for (auto &nor : m_nor)
        nor->dump();
    for (auto &flipflop : m_flipflops)
        flipflop->dump();
}
