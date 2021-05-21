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
    Component4040::Component4040():
        ACalculationComponent(ComponentType::C4040, 16, {
            CLOCK, RESET
        }, {
            Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12
        }),
        m_invert_clock{std::make_unique<GateNOT>()},
        m_counter{0}
    {
        setLinkInternal(CLOCK, *m_invert_clock, GateNOT::INPUT);
    }

    void Component4040::computeOutputs()
    {
        const Tristate clock = compute(*m_invert_clock, GateNOT::OUTPUT);
        const Tristate reset = compute(RESET);
        constexpr std::array<std::size_t, 12> counter_outputs{Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12};

        if (reset == UNDEFINED || (reset == FALSE && clock == UNDEFINED)) {
            setAllOutputs(UNDEFINED);
            return;
        }
        if (reset == FALSE && clock == FALSE)
            return;

        m_counter = (m_counter + 1) * (!reset);
        for (std::size_t bit = 0; bit < counter_outputs.size(); ++bit)
            output(counter_outputs.at(bit)) = static_cast<Tristate>((m_counter & (1UL << bit)) >> bit);
    }
} // namespace nts
