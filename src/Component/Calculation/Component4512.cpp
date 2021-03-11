/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Component4512
*/

#include <array>
#include "Component4512.hpp"
#include "GateNOT.hpp"

nts::Component4512::Component4512() noexcept:
    ACalculationComponent(ComponentType::C4512, 16, {
        X0, X1, X2, X3, X4, X5, X6, X7, INHIBIT, INPUT_A, INPUT_B, INPUT_C, INPUT_OE
    },{
        OUTPUT_Z
    }),
    m_invert_oe{std::make_unique<nts::GateNOT>()}
{
    m_pins[INPUT_OE].setLinkWithInternalComponent(*m_invert_oe, GateNOT::INPUT);
}

void nts::Component4512::computeOutputs(std::size_t tick)
{
    unsigned char address = 0;
    const nts::Tristate input_a = m_pins[INPUT_A].compute(tick);
    const nts::Tristate input_b = m_pins[INPUT_B].compute(tick);
    const nts::Tristate input_c = m_pins[INPUT_C].compute(tick);
    const nts::Tristate inhibit = m_pins[INHIBIT].compute(tick);
    const nts::Tristate output_enabled = computeInternalComponent(*m_invert_oe, GateNOT::OUTPUT);
    std::array<nts::Tristate, 8> x_inputs;

    std::size_t index = 0;
    for (std::size_t pin : {X0, X1, X2, X3, X4, X5, X6, X7})
        x_inputs[index++] = m_pins[pin].compute(tick);
    if (output_enabled == nts::FALSE || output_enabled == nts::UNDEFINED || inhibit == nts::UNDEFINED) {
        m_output_pins[OUTPUT_Z] = nts::UNDEFINED;
        return;
    }
    if (inhibit == nts::TRUE) {
        m_output_pins[OUTPUT_Z] = nts::FALSE;
        return;
    }
    if (input_a == nts::UNDEFINED || input_b == nts::UNDEFINED || input_c == nts::UNDEFINED) {
        m_output_pins[OUTPUT_Z] = nts::UNDEFINED;
        return;
    }
    address = (input_c << 2) | (input_b << 1) | input_a;
    m_output_pins[OUTPUT_Z] = x_inputs.at(address);
}
