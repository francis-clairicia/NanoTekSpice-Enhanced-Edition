/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4017
*/

#include <algorithm>
#include "Component4017.hpp"
#include "GateNOT.hpp"
#include "GateAND.hpp"

namespace nts
{
    Component4017::Component4017():
        ACalculationComponent(ComponentType::C4017, 16, {CP0, CP1, MR}, {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q5_9}),
        m_invert_cp1{std::make_unique<GateNOT>()},
        m_and_gate_clock{std::make_unique<GateAND>()},
        m_shift{0}
    {
        setLinkInternal(CP1, *m_invert_cp1, GateNOT::INPUT);
        setLinkInternal(CP0, *m_and_gate_clock, GateAND::INPUT1);
        m_and_gate_clock->setLink(GateAND::INPUT2, *m_invert_cp1, GateNOT::OUTPUT);
    }

    void Component4017::computeOutputs()
    {
        const Tristate master_reset = compute(MR);
        const Tristate clock = compute(*m_and_gate_clock, GateAND::OUTPUT);
        constexpr std::array<std::size_t, 10> pins{Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9};

        if (master_reset == UNDEFINED || (master_reset == FALSE && clock == UNDEFINED)) {
            setAllOutputs(UNDEFINED);
            return;
        }
        if (master_reset == FALSE && clock == FALSE)
            return;
        m_shift = ((m_shift + 1) % pins.size()) * (!master_reset);
        for (std::size_t index = 0; index < pins.size(); ++index) {
            output(pins.at(index)) = static_cast<Tristate>(index == m_shift);
        }

        constexpr std::array<std::size_t, 5> output_5_to_9{Q5, Q6, Q7, Q8, Q9};
        output(Q5_9) = static_cast<Tristate>(std::all_of(output_5_to_9.begin(), output_5_to_9.end(), 
                                            [this](std::size_t pin)
                                            {
                                                return output(pin) == FALSE;
                                            }));
    }
} // namespace nts