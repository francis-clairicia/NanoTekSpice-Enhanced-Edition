/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4514
*/

#include <algorithm>
#include "Component4514.hpp"

namespace nts
{
    Component4514::Component4514():
        ACalculationComponent(ComponentType::C4514, 24, {
            IN_A, IN_B, IN_C, IN_D, INHIBIT, STROBE
        }, {
            OUT_S0, OUT_S1, OUT_S2, OUT_S3, OUT_S4, OUT_S5, OUT_S6, OUT_S7,
            OUT_S8, OUT_S9, OUT_S10, OUT_S11, OUT_S12, OUT_S13, OUT_S14, OUT_S15
        }),
        m_latch{std::make_unique<Latch>()}
    {
        setLinkInternal(IN_A, *m_latch, Latch::INPUT_A);
        setLinkInternal(IN_B, *m_latch, Latch::INPUT_B);
        setLinkInternal(IN_C, *m_latch, Latch::INPUT_C);
        setLinkInternal(IN_D, *m_latch, Latch::INPUT_D);
        setLinkInternal(STROBE, *m_latch, Latch::INPUT_STROBE);
    }

    void Component4514::computeOutputs()
    {
        std::size_t address = 0;
        const Tristate inhibit = compute(INHIBIT);
        const std::array<Tristate, 4> input_address{
            compute(*m_latch, Latch::OUTPUT_A),
            compute(*m_latch, Latch::OUTPUT_B),
            compute(*m_latch, Latch::OUTPUT_C),
            compute(*m_latch, Latch::OUTPUT_D)
        };
        constexpr std::array<std::size_t, 16> output_pins{
            OUT_S0, OUT_S1, OUT_S2, OUT_S3, OUT_S4, OUT_S5, OUT_S6, OUT_S7,
            OUT_S8, OUT_S9, OUT_S10, OUT_S11, OUT_S12, OUT_S13, OUT_S14, OUT_S15
        };

        if (inhibit == UNDEFINED || inhibit == TRUE) {
            setAllOutputs((inhibit == UNDEFINED) ? UNDEFINED : FALSE);
            return;
        }

        if (std::any_of(input_address.begin(), input_address.end(), [](Tristate value){return value == UNDEFINED;})) {
            setAllOutputs(UNDEFINED);
            return;
        }

        for (std::size_t bit = 0; bit < input_address.size(); ++bit)
            address |= input_address.at(bit) << bit;

        for (std::size_t out = 0; out < output_pins.size(); ++out)
            output(output_pins.at(out)) = static_cast<Tristate>(out == address);
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

    void Component4514::Latch::computeOutputs()
    {
        const Tristate strobe = compute(INPUT_STROBE);

        if (strobe == UNDEFINED) {
            setAllOutputs(UNDEFINED);
            return;
        }
        if (strobe == FALSE)
            return;
        output(OUTPUT_A) = compute(INPUT_A);
        output(OUTPUT_B) = compute(INPUT_B);
        output(OUTPUT_C) = compute(INPUT_C);
        output(OUTPUT_D) = compute(INPUT_D);
    }
} // namespace nts
