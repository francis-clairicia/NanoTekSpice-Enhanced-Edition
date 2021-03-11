/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** DTypeFlipFlopWithSR
*/

#include "DTypeFlipFlopWithSR.hpp"
#include "GateNOT.hpp"

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
    ACalculationComponent(ComponentType::DTypeFlipFlopWithSR, 6, {CLOCK, RESET, DATA, SET}, {Q, Qn}),
    m_invert_data{std::make_unique<GateNOT>()}
{
    m_pins[DATA].setLinkWithInternalComponent(*m_invert_data, GateNOT::INPUT);
}

void nts::DTypeFlipFlopWithSR::computeOutputs(std::size_t tick)
{
    const nts::Tristate data = m_pins[DATA].compute(tick);
    const nts::Tristate data_invert = computeInternalComponent(*m_invert_data, GateNOT::OUTPUT);
    const nts::Tristate clock = m_pins[CLOCK].compute(tick);
    const nts::Tristate reset = m_pins[RESET].compute(tick);
    const nts::Tristate set = m_pins[SET].compute(tick);

    if (reset == nts::UNDEFINED || set == nts::UNDEFINED) {
        m_output_pins[Q] = nts::UNDEFINED;
        m_output_pins[Qn] = nts::UNDEFINED;
        return;
    }
    if (reset == nts::TRUE || set == nts::TRUE) {
        m_output_pins[Q] = set;
        m_output_pins[Qn] = reset;
        return;
    }
    if (clock == nts::TRUE) {
        m_output_pins[Q] = data;
        m_output_pins[Qn] = data_invert;
    } else if (clock == nts::UNDEFINED) {
        m_output_pins[Q] = nts::UNDEFINED;
        m_output_pins[Qn] = nts::UNDEFINED;
    }
}