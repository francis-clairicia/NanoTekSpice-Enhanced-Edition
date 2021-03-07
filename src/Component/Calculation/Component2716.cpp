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

static const std::string ROM_BUFFER_FILE{"./rom.bin"};

nts::Component2716::Component2716() noexcept:
    ACalculationComponent(ComponentType::C2716, 24, {
        A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, CHIP_ENABLED, OUTPUT_ENABLED
    }, {
        Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7
    }),
    m_invert_oe{std::make_unique<GateNOT>()},
    m_invert_ce_pgm{std::make_unique<GateNOT>()}
{
    std::fill(m_memory.begin(), m_memory.end(), 0);
    std::ifstream rom_stream{ROM_BUFFER_FILE, std::ios_base::in | std::ios_base::binary};

    if (!rom_stream)
        return;
    for (std::size_t address = 0; !rom_stream.eof() && address < m_memory.size(); ++address)
        rom_stream >> m_memory[address];
    rom_stream.close();

    m_invert_oe->setLink(GateNOT::INPUT, *this, OUTPUT_ENABLED);
    m_invert_ce_pgm->setLink(GateNOT::INPUT, *this, CHIP_ENABLED);
}

nts::Component2716::~Component2716() noexcept
{
}

void nts::Component2716::computeOutputs()
{
    std::array<nts::Tristate, 11> address_input;
    const std::array<std::size_t, 11> address_pin{A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10};

    nts::Tristate output_enabled = computeInternalComponent(*m_invert_oe, GateNOT::OUTPUT);
    nts::Tristate chipset_enabled = computeInternalComponent(*m_invert_ce_pgm, GateNOT::OUTPUT);

    for (std::size_t bit = 0; bit < address_input.size(); ++bit)
        address_input[bit] = compute(address_pin.at(bit));

    if (output_enabled == nts::FALSE || chipset_enabled == nts::FALSE || output_enabled == nts::UNDEFINED || chipset_enabled == nts::UNDEFINED) {
        for (auto &pair : m_output_pins)
            pair.second = nts::UNDEFINED;
        return;
    }

    if (std::any_of(address_input.begin(), address_input.end(), [](const nts::Tristate &v){return v == nts::UNDEFINED;})) {
        for (auto &pair : m_output_pins)
            pair.second = nts::UNDEFINED;
        return;
    }

    unsigned short int address = 0;

    for (std::size_t bit = 0; bit < address_input.size(); ++bit)
        address |= (address_input.at(bit) << bit);

    const unsigned char &byte = m_memory.at(address);

    for (std::size_t bit = 0; bit < m_output_pin_list.size(); ++bit)
        m_output_pins[m_output_pin_list.at(bit)] = static_cast<nts::Tristate>((byte & (1 << bit)) >> bit);
}