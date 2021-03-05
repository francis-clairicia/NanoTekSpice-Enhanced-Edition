/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4040
*/

#include "Component4040.hpp"
#include "GateNOT.hpp"
#include "get_map_keys.hpp"

nts::Component4040::Component4040() noexcept:
    ACalculationComponent(ComponentType::C4040, 16, {
        CLOCK, RESET
    }, {
        Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12
    }),
    m_invert_clock{std::make_unique<GateNOT>()},
    m_counter{0}
{
    m_invert_clock->setLink(GateNOT::INPUT, *this, CLOCK);
}

nts::Component4040::~Component4040() noexcept
{
}

void nts::Component4040::computeOutputs()
{
    nts::Tristate clock = computeInternalComponent(*m_invert_clock, GateNOT::OUTPUT);
    nts::Tristate reset = compute(RESET);
    nts::componentPin_t pins{get_map_keys(m_output_pins)};
    std::size_t nb_pins = m_output_pins.size();

    if (reset == nts::UNDEFINED || (reset == nts::FALSE && clock == nts::UNDEFINED)) {
        for (auto &pair : m_output_pins)
            pair.second = nts::UNDEFINED;
        return;
    }
    if (reset == nts::FALSE && clock == nts::FALSE)
        return;

    m_counter = (m_counter + 1) * (!reset);
    for (std::size_t bit = 0; bit < nb_pins; ++bit)
        m_output_pins[pins.at(nb_pins - 1 - bit)] = static_cast<nts::Tristate>((m_counter & (1UL << bit)) >> bit);
}
