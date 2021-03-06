/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4017
*/

#include <algorithm>
#include "Component4017.hpp"
#include "GateNOT.hpp"
#include "GateAND.hpp"

nts::Component4017::Component4017() noexcept:
    ACalculationComponent(ComponentType::C4017, 16, {CP0, CP1, MR}, {Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q5_9}),
    m_invert_cp1{std::make_unique<GateNOT>()},
    m_and_gate_clock{std::make_unique<GateAND>()},
    m_shift{0}
{
    m_invert_cp1->setLink(GateNOT::INPUT, *this, CP1);
    m_and_gate_clock->setLink(GateAND::INPUT1, *this, CP0);
    m_and_gate_clock->setLink(GateAND::INPUT2, *m_invert_cp1, GateNOT::OUTPUT);
}

nts::Component4017::~Component4017() noexcept
{
}

void nts::Component4017::computeOutputs()
{
    nts::Tristate master_reset = compute(MR);
    nts::Tristate clock = computeInternalComponent(*m_and_gate_clock, GateAND::OUTPUT);
    nts::componentPin_t pins{m_output_pin_list};

    pins.pop_back();
    if (master_reset == nts::UNDEFINED || (master_reset == nts::FALSE && clock == nts::UNDEFINED)) {
        for (auto &pair : m_output_pins)
            pair.second = nts::UNDEFINED;
        return;
    }
    if (master_reset == nts::FALSE && clock == nts::FALSE)
        return;
    m_shift = ((m_shift + 1) % pins.size()) * (!master_reset);
    for (std::size_t index = 0; index < pins.size(); ++index) {
        m_output_pins[pins.at(index)] = static_cast<nts::Tristate>(index == m_shift);
    }

    nts::componentPin_t output_5_to_9{Q5, Q6, Q7, Q8, Q9};
    m_output_pins[Q5_9] = static_cast<nts::Tristate>(std::all_of(output_5_to_9.begin(), output_5_to_9.end(),
                                                    [this](const std::size_t &pin){return this->m_output_pins[pin] == nts::FALSE;}));
}
