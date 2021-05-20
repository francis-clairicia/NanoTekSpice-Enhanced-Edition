/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Component4512
*/

#include <array>
#include "Component4512.hpp"
#include "GateNOT.hpp"

namespace nts
{
    Component4512::Component4512() noexcept:
        ACalculationComponent(ComponentType::C4512, 16, {
            X0, X1, X2, X3, X4, X5, X6, X7, INHIBIT, INPUT_A, INPUT_B, INPUT_C, INPUT_OE
        },{
            OUTPUT_Z
        }),
        m_invert_oe{std::make_unique<GateNOT>()}
    {
        m_pins.setLinkInternal(*this, INPUT_OE, *m_invert_oe, GateNOT::INPUT);
    }

    void Component4512::computeOutputs()
    {
        unsigned char address = 0;
        const Tristate input_a = m_pins.input(INPUT_A);
        const Tristate input_b = m_pins.input(INPUT_B);
        const Tristate input_c = m_pins.input(INPUT_C);
        const Tristate inhibit = m_pins.input(INHIBIT);
        const Tristate output_enabled = m_pins.computeInternal(*m_invert_oe, GateNOT::OUTPUT);
        std::array<Tristate, 8> x_inputs;

        std::size_t index = 0;
        for (std::size_t pin : {X0, X1, X2, X3, X4, X5, X6, X7})
            x_inputs[index++] = m_pins.input(pin);
        if (output_enabled == FALSE || output_enabled == UNDEFINED || inhibit == UNDEFINED) {
            m_pins.output(OUTPUT_Z) = UNDEFINED;
            return;
        }
        if (inhibit == TRUE) {
            m_pins.output(OUTPUT_Z) = FALSE;
            return;
        }
        if (input_a == UNDEFINED || input_b == UNDEFINED || input_c == UNDEFINED) {
            m_pins.output(OUTPUT_Z) = UNDEFINED;
            return;
        }
        address = (input_c << 2) | (input_b << 1) | input_a;
        m_pins.output(OUTPUT_Z) = x_inputs.at(address);
    }
} // namespace nts
