/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4040
*/

#include "Component4040.hpp"
#include "GateNOT.hpp"

namespace nts
{
    Component4040::Component4040() noexcept:
        ACalculationComponent(ComponentType::C4040, 16, {
            CLOCK, RESET
        }, {
            Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12
        }),
        m_invert_clock{std::make_unique<GateNOT>()},
        m_counter{0}
    {
        m_pins.setLinkInternal(*this, CLOCK, *m_invert_clock, GateNOT::INPUT);
    }

    void Component4040::computeOutputs()
    {
        const Tristate clock = m_pins.computeInternal(*m_invert_clock, GateNOT::OUTPUT);
        const Tristate reset = m_pins.input(RESET);

        if (reset == UNDEFINED || (reset == FALSE && clock == UNDEFINED)) {
            m_pins.setAllOutputs(UNDEFINED);
            return;
        }
        if (reset == FALSE && clock == FALSE)
            return;

        m_counter = (m_counter + 1) * (!reset);
        for (std::size_t bit = 0; bit < m_pins.getOutputPins().size(); ++bit)
            m_pins.output(m_pins.getOutputPins().at(bit)) = static_cast<Tristate>((m_counter & (1UL << bit)) >> bit);
    }
} // namespace nts
