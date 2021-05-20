/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Component2716
*/

#include <algorithm>
#include <fstream>
#include "Component2716.hpp"
#include "GateNOT.hpp"

namespace
{
    constexpr std::string_view ROM_BUFFER_FILE{"./rom.bin"};
} // namespace

namespace nts
{
    Component2716::Component2716() noexcept:
        ACalculationComponent(ComponentType::C2716, 24, {
            A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, CHIP_ENABLED, OUTPUT_ENABLED
        }, {
            Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7
        }),
        m_invert_oe{std::make_unique<GateNOT>()},
        m_invert_ce_pgm{std::make_unique<GateNOT>()}
    {
        std::fill(m_memory.begin(), m_memory.end(), 0);
        std::ifstream rom_stream{ROM_BUFFER_FILE.data(), std::ios_base::binary};

        if (!rom_stream)
            return;
        rom_stream.read(m_memory.data(), m_memory.size());
        rom_stream.close();

        m_pins.setLinkInternal(*this, OUTPUT_ENABLED, *m_invert_oe, GateNOT::INPUT);
        m_pins.setLinkInternal(*this, CHIP_ENABLED, *m_invert_ce_pgm, GateNOT::INPUT);
    }

    void Component2716::computeOutputs()
    {
        std::array<Tristate, 11> address_input;
        constexpr std::array<std::size_t, 11> address_pin{A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10};
        constexpr std::array<std::size_t, 8> byte_output{Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7};

        Tristate output_enabled = m_pins.computeInternal(*m_invert_oe, GateNOT::OUTPUT);
        Tristate chipset_enabled = m_pins.computeInternal(*m_invert_ce_pgm, GateNOT::OUTPUT);

        for (std::size_t bit = 0; bit < address_input.size(); ++bit)
            address_input[bit] = m_pins.input(address_pin.at(bit));

        if (output_enabled == FALSE || chipset_enabled == FALSE || output_enabled == UNDEFINED || chipset_enabled == UNDEFINED) {
            m_pins.setAllOutputs(UNDEFINED);
            return;
        }

        if (std::any_of(address_input.begin(), address_input.end(), [](Tristate v){return v == UNDEFINED;})) {
            m_pins.setAllOutputs(UNDEFINED);
            return;
        }

        unsigned short int address = 0;

        for (std::size_t bit = 0; bit < address_input.size(); ++bit)
            address |= (address_input.at(bit) << bit);

        const char byte = m_memory.at(address);

        for (std::size_t bit = 0; bit < byte_output.size(); ++bit)
            m_pins.output(byte_output.at(bit)) = static_cast<Tristate>((byte & (1 << bit)) >> bit);
    }
} // namespace nts