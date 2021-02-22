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
    m_gateQ(std::make_unique<QGate>())
{
    m_gateQ->setLink(QGate::DATA, *this, DATA);
    m_gateQ->setLink(QGate::CLOCK, *this, CLOCK);
    m_gateQ->setLink(QGate::RESET, *this, RESET);
    m_gateQ->setLink(QGate::SET, *this, SET);
    setLinkInternal(Q, *m_gateQ, QGate::Q);
    setLinkInternal(Qn, *m_gateQ, QGate::Qn);
}

nts::DTypeFlipFlopWithSR::~DTypeFlipFlopWithSR()
{
}

void nts::DTypeFlipFlopWithSR::simulate(std::size_t tick)
{
    m_gateQ->simulate(tick);
}

void nts::DTypeFlipFlopWithSR::dumpInternalComponents() const
{
}

nts::DTypeFlipFlopWithSR::QGate::QGate() noexcept:
    AGate(ThirdPartyComponentType, 6, {QGate::DATA, QGate::CLOCK, QGate::RESET, QGate::SET}, {QGate::Q, QGate::Qn}),
    m_Q_buffer(nts::UNDEFINED), m_Qn_buffer(nts::UNDEFINED)
{
}

nts::Tristate nts::DTypeFlipFlopWithSR::QGate::computeOutput(std::size_t pin)
{
    if (!m_computed) {
        m_computed = true;

        nts::Tristate data = compute(QGate::DATA);
        nts::Tristate clock = compute(QGate::CLOCK);
        nts::Tristate reset = compute(QGate::RESET);
        nts::Tristate set = compute(QGate::SET);

        if (reset == nts::UNDEFINED || set == nts::UNDEFINED || clock == nts::UNDEFINED)
            return nts::UNDEFINED;
        if (reset == nts::TRUE && set == nts::TRUE) {
            m_Q_buffer = nts::TRUE;
            m_Qn_buffer = nts::TRUE;
        } else if (reset == nts::TRUE) {
            m_Q_buffer = nts::FALSE;
            m_Qn_buffer = nts::TRUE;
        } else if (set == nts::TRUE) {
            m_Q_buffer = nts::TRUE;
            m_Qn_buffer = nts::FALSE;
        } else if (clock == nts::TRUE) {
            m_Q_buffer = data;
            m_Qn_buffer = static_cast<nts::Tristate>(!data);
        }
    }
    if (pin == Q)
        return m_Q_buffer;
    if (pin == Qn)
        return m_Qn_buffer;
    return nts::UNDEFINED;
}