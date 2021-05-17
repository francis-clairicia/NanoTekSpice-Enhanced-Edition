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

namespace nts
{
    DTypeFlipFlopWithSR::DTypeFlipFlopWithSR() noexcept:
        ACalculationComponent(ComponentType::DTypeFlipFlopWithSR, 6, {CLOCK, RESET, DATA, SET}, {Q, Qn}),
        m_invert_data{std::make_unique<GateNOT>()}
    {
        m_pins[DATA].setLinkWithInternalComponent(*m_invert_data, GateNOT::INPUT);
    }

    void DTypeFlipFlopWithSR::computeOutputs(std::size_t tick)
    {
        const Tristate data = m_pins[DATA].compute(tick);
        const Tristate data_invert = computeInternalComponent(*m_invert_data, GateNOT::OUTPUT);
        const Tristate clock = m_pins[CLOCK].compute(tick);
        const Tristate reset = m_pins[RESET].compute(tick);
        const Tristate set = m_pins[SET].compute(tick);

        if (reset == UNDEFINED || set == UNDEFINED) {
            m_output_pins[Q] = UNDEFINED;
            m_output_pins[Qn] = UNDEFINED;
            return;
        }
        if (reset == TRUE || set == TRUE) {
            m_output_pins[Q] = set;
            m_output_pins[Qn] = reset;
            return;
        }
        if (clock == TRUE) {
            m_output_pins[Q] = data;
            m_output_pins[Qn] = data_invert;
        } else if (clock == UNDEFINED) {
            m_output_pins[Q] = UNDEFINED;
            m_output_pins[Qn] = UNDEFINED;
        }
    }
} // namespace nts
