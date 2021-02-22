/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** DTypeFlipFlopWithSR
*/

#include "DTypeFlipFlopWithSR.hpp"

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
    m_gateQ(std::make_unique<QGate>(false)),
    m_gateQn(std::make_unique<QGate>(true))
{
    // Q output
    m_gateQ->setLink(QGate::DATA, *this, DATA);
    m_gateQ->setLink(QGate::CLOCK, *this, CLOCK);
    m_gateQ->setLink(QGate::RESET, *this, RESET);
    m_gateQ->setLink(QGate::SET, *this, SET);
    setLinkInternal(Q, *m_gateQ, QGate::OUTPUT);

    // /Q (Qn) output
    m_gateQn->setLink(QGate::DATA, *this, DATA);
    m_gateQn->setLink(QGate::CLOCK, *this, CLOCK);
    m_gateQn->setLink(QGate::RESET, *this, RESET);
    m_gateQn->setLink(QGate::SET, *this, SET);
    setLinkInternal(Qn, *m_gateQn, QGate::OUTPUT);
}

nts::DTypeFlipFlopWithSR::~DTypeFlipFlopWithSR()
{
}

void nts::DTypeFlipFlopWithSR::simulate(std::size_t tick)
{
    m_gateQ->simulate(tick);
    m_gateQn->simulate(tick);
}

void nts::DTypeFlipFlopWithSR::dumpInternalComponents() const
{
}

nts::DTypeFlipFlopWithSR::QGate::QGate(bool invert) noexcept:
    AGate(ThirdPartyComponentType, 5, {QGate::DATA, QGate::CLOCK, QGate::RESET, QGate::SET}, QGate::OUTPUT),
    m_buffer(nts::UNDEFINED), m_invert(invert)
{
}

nts::Tristate nts::DTypeFlipFlopWithSR::QGate::computeOutput()
{
    nts::Tristate data = compute(QGate::DATA);
    nts::Tristate clock = compute(QGate::CLOCK);
    nts::Tristate reset = compute(QGate::RESET);
    nts::Tristate set = compute(QGate::SET);

    if (reset == nts::UNDEFINED || set == nts::UNDEFINED || clock == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (reset == nts::TRUE && set == nts::TRUE)
        m_buffer = nts::TRUE;
    else if (reset == nts::TRUE)
        m_buffer = static_cast<nts::Tristate>(m_invert ^ nts::FALSE);
    else if (set == nts::TRUE)
        m_buffer = static_cast<nts::Tristate>(m_invert ^ nts::TRUE);
    else if (clock == nts::TRUE)
        m_buffer = static_cast<nts::Tristate>(m_invert ^ data);
    return m_buffer;
}