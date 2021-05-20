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
        m_invert_data->setLink(GateNOT::INPUT, *this, DATA);
        m_pins.setLinkInternal(*this, DATA, *m_invert_data, GateNOT::INPUT);
    }

    void DTypeFlipFlopWithSR::computeOutputs()
    {
        const Tristate data = m_pins.input(DATA);
        const Tristate data_invert = m_pins.computeInternal(*m_invert_data, GateNOT::OUTPUT);
        const Tristate clock = m_pins.input(CLOCK);
        const Tristate reset = m_pins.input(RESET);
        const Tristate set = m_pins.input(SET);

        if (reset == UNDEFINED || set == UNDEFINED) {
            m_pins.output(Q) = UNDEFINED;
            m_pins.output(Qn) = UNDEFINED;
            return;
        }
        if (reset == TRUE || set == TRUE) {
            m_pins.output(Q) = set;
            m_pins.output(Qn) = reset;
            return;
        }
        if (clock == TRUE) {
            m_pins.output(Q) = data;
            m_pins.output(Qn) = data_invert;
        } else if (clock == UNDEFINED) {
            m_pins.output(Q) = UNDEFINED;
            m_pins.output(Qn) = UNDEFINED;
        }
    }
} // namespace nts
