/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
    DTypeFlipFlopWithSR::DTypeFlipFlopWithSR():
        ACalculationComponent(ComponentType::DTypeFlipFlopWithSR, 6, {CLOCK, RESET, DATA, SET}, {Q, Qn}),
        m_invert_data{std::make_unique<GateNOT>()}
    {
        setLinkInternal(DATA, *m_invert_data, GateNOT::INPUT);
    }

    void DTypeFlipFlopWithSR::computeOutputs()
    {
        const Tristate data = compute(DATA);
        const Tristate data_invert = compute(*m_invert_data, GateNOT::OUTPUT);
        const Tristate clock = compute(CLOCK);
        const Tristate reset = compute(RESET);
        const Tristate set = compute(SET);

        if (reset == UNDEFINED || set == UNDEFINED) {
            output(Q) = UNDEFINED;
            output(Qn) = UNDEFINED;
            return;
        }
        if (reset == TRUE || set == TRUE) {
            output(Q) = set;
            output(Qn) = reset;
            return;
        }
        if (clock == TRUE) {
            output(Q) = data;
            output(Qn) = data_invert;
        } else if (clock == UNDEFINED) {
            output(Q) = UNDEFINED;
            output(Qn) = UNDEFINED;
        }
    }
} // namespace nts
