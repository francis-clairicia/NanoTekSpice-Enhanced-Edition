/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Component4514
*/

#include <algorithm>
#include "Component4514.hpp"

namespace nts
{
    Component4514::Component4514() noexcept:
        BoxComponent(ComponentType::C4514, 24, {
            IN_A, IN_B, IN_C, IN_D, INHIBIT, STROBE
        }, {
            OUT_S0, OUT_S1, OUT_S2, OUT_S3, OUT_S4, OUT_S5, OUT_S6, OUT_S7,
            OUT_S8, OUT_S9, OUT_S10, OUT_S11, OUT_S12, OUT_S13, OUT_S14, OUT_S15
        }),
        m_latch{std::make_unique<Latch>()},
        m_decoder{std::make_unique<Decoder>()}
    {
        setLinkInternal(IN_A, *m_latch, Latch::INPUT_A);
        setLinkInternal(IN_B, *m_latch, Latch::INPUT_B);
        setLinkInternal(IN_C, *m_latch, Latch::INPUT_C);
        setLinkInternal(IN_D, *m_latch, Latch::INPUT_D);
        setLinkInternal(STROBE, *m_latch, Latch::INPUT_STROBE);

        m_decoder->setLink(Decoder::INPUT_A, *m_latch, Latch::OUTPUT_A);
        m_decoder->setLink(Decoder::INPUT_B, *m_latch, Latch::OUTPUT_B);
        m_decoder->setLink(Decoder::INPUT_C, *m_latch, Latch::OUTPUT_C);
        m_decoder->setLink(Decoder::INPUT_D, *m_latch, Latch::OUTPUT_D);
        setLinkInternal(INHIBIT, *m_decoder, Decoder::INPUT_INHIBIT);

        setLinkInternal(OUT_S0, *m_decoder, Decoder::OUTPUT_S0);
        setLinkInternal(OUT_S1, *m_decoder, Decoder::OUTPUT_S1);
        setLinkInternal(OUT_S2, *m_decoder, Decoder::OUTPUT_S2);
        setLinkInternal(OUT_S3, *m_decoder, Decoder::OUTPUT_S3);
        setLinkInternal(OUT_S4, *m_decoder, Decoder::OUTPUT_S4);
        setLinkInternal(OUT_S5, *m_decoder, Decoder::OUTPUT_S5);
        setLinkInternal(OUT_S6, *m_decoder, Decoder::OUTPUT_S6);
        setLinkInternal(OUT_S7, *m_decoder, Decoder::OUTPUT_S7);
        setLinkInternal(OUT_S8, *m_decoder, Decoder::OUTPUT_S8);
        setLinkInternal(OUT_S9, *m_decoder, Decoder::OUTPUT_S9);
        setLinkInternal(OUT_S10, *m_decoder, Decoder::OUTPUT_S10);
        setLinkInternal(OUT_S11, *m_decoder, Decoder::OUTPUT_S11);
        setLinkInternal(OUT_S12, *m_decoder, Decoder::OUTPUT_S12);
        setLinkInternal(OUT_S13, *m_decoder, Decoder::OUTPUT_S13);
        setLinkInternal(OUT_S14, *m_decoder, Decoder::OUTPUT_S14);
        setLinkInternal(OUT_S15, *m_decoder, Decoder::OUTPUT_S15);
    }

    /* -------------------- Latch component -------------------- */

    Component4514::Latch::Latch() noexcept:
        ACalculationComponent(ComponentType::ThirdParty, 9, {
            INPUT_A, INPUT_B, INPUT_C, INPUT_D, INPUT_STROBE
        }, {
            OUTPUT_A, OUTPUT_B, OUTPUT_C, OUTPUT_D
        })
    {
    }

    void Component4514::Latch::computeOutputs(std::size_t tick)
    {
        const Tristate input_a = m_pins[INPUT_A].compute(tick);
        const Tristate input_b = m_pins[INPUT_B].compute(tick);
        const Tristate input_c = m_pins[INPUT_C].compute(tick);
        const Tristate input_d = m_pins[INPUT_D].compute(tick);
        const Tristate strobe = m_pins[INPUT_STROBE].compute(tick);

        if (strobe == UNDEFINED) {
            for (auto &pair : m_output_pins)
                pair.second = UNDEFINED;
            return;
        }
        if (strobe == FALSE)
            return;
        m_output_pins[OUTPUT_A] = input_a;
        m_output_pins[OUTPUT_B] = input_b;
        m_output_pins[OUTPUT_C] = input_c;
        m_output_pins[OUTPUT_D] = input_d;
    }

    /* -------------------- Decoder component -------------------- */

    Component4514::Decoder::Decoder() noexcept:
        ACalculationComponent(ComponentType::ThirdParty, 21, {
            INPUT_A, INPUT_B, INPUT_C, INPUT_D, INPUT_INHIBIT
        }, {
            OUTPUT_S0, OUTPUT_S1, OUTPUT_S2, OUTPUT_S3, OUTPUT_S4, OUTPUT_S5, OUTPUT_S6, OUTPUT_S7,
            OUTPUT_S8, OUTPUT_S9, OUTPUT_S10, OUTPUT_S11, OUTPUT_S12, OUTPUT_S13, OUTPUT_S14, OUTPUT_S15
        })
    {
    }

    void Component4514::Decoder::computeOutputs(std::size_t tick)
    {
        std::size_t address = 0;
        const Tristate input_a = m_pins[INPUT_A].compute(tick);
        const Tristate input_b = m_pins[INPUT_B].compute(tick);
        const Tristate input_c = m_pins[INPUT_C].compute(tick);
        const Tristate input_d = m_pins[INPUT_D].compute(tick);
        const Tristate inhibit = m_pins[INPUT_INHIBIT].compute(tick);
        const std::array<Tristate, 4> input_address{input_a, input_b, input_c, input_d};

        if (inhibit == UNDEFINED || inhibit == TRUE) {
            for (auto &pair : m_output_pins)
                pair.second = (inhibit == UNDEFINED) ? UNDEFINED : FALSE;
            return;
        }

        if (std::any_of(input_address.begin(), input_address.end(), [](Tristate value){return value == UNDEFINED;})) {
            for (auto &pair : m_output_pins)
                pair.second = UNDEFINED;
            return;
        }

        address = (input_d << 3) | (input_c << 2) | (input_b << 1) | input_a;

        for (std::size_t out = 0; out < m_pins.getOutputPins().size(); ++out)
            m_output_pins[m_pins.getOutputPins().at(out)] = static_cast<Tristate>(out == address);
    }
} // namespace nts
