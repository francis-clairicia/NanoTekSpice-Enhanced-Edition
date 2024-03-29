/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component2716
*/

#include <fstream>
#include "Component2716.hpp"
#include "GateNOT.hpp"
#include "get_tristate_bit.hpp"

namespace
{
    constexpr std::string_view ROM_BUFFER_FILE{"./rom.bin"};
} // namespace

namespace nts
{
    Component2716::Component2716():
        ACalculationComponent(ComponentType::C2716, 24, {
            A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, CHIP_ENABLED, OUTPUT_ENABLED
        }, {
            Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7
        }),
        m_invert_oe{std::make_unique<GateNOT>()},
        m_invert_ce_pgm{std::make_unique<GateNOT>()}
    {
        std::ifstream rom_stream{ROM_BUFFER_FILE.data(), std::ios_base::binary};

        if (rom_stream.is_open()) {
            rom_stream >> m_memory;
        }

        setLinkInternal(OUTPUT_ENABLED, *m_invert_oe, GateNOT::INPUT);
        setLinkInternal(CHIP_ENABLED, *m_invert_ce_pgm, GateNOT::INPUT);
    }

    void Component2716::computeOutputs()
    {
        constexpr std::array<std::size_t, 8> byte_output{Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7};
        const Tristate output_enabled = compute(*m_invert_oe, GateNOT::OUTPUT);
        const Tristate chipset_enabled = compute(*m_invert_ce_pgm, GateNOT::OUTPUT);

        if (output_enabled == TRUE || chipset_enabled == TRUE || output_enabled == UNDEFINED || chipset_enabled == UNDEFINED) {
            setAllOutputs(UNDEFINED);
            return;
        }

        std::size_t address = 0;
        std::size_t bit = 0;
        for (auto pin : {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10}) {
            Tristate input = compute(pin);
            if (input == UNDEFINED) {
                setAllOutputs(UNDEFINED);
                return;
            }
            address |= (input != FALSE) << bit++;
        }

        const auto byte = m_memory[address];

        for (std::size_t bit = 0; bit < byte_output.size(); ++bit)
            output(byte_output.at(bit)) = get_tristate_bit(byte, bit);
    }
} // namespace nts