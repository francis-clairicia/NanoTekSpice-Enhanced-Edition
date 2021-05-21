/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4801
*/

#include "Component4801.hpp"
#include "GateNOT.hpp"
#include "get_tristate_bit.hpp"

namespace nts
{
    Component4801::Component4801():
        ACalculationComponent{ComponentType::C4801, 24, {
            A0, A1, A2, A3, A4, A5, A6, A7, A8, A9,
            DQ0, DQ1, DQ2, DQ3, DQ4, DQ5, DQ6, DQ7,
            CE, OE, WE
        }, {
            DQ0, DQ1, DQ2, DQ3, DQ4, DQ5, DQ6, DQ7
        }}
    {
    }

    void Component4801::computeOutputs()
    {
        const Tristate chipset_enabled = compute(CE);
        const Tristate output_enabled = compute(OE);
        const Tristate write_enabled = compute(WE);

        if (chipset_enabled == FALSE || chipset_enabled == UNDEFINED) {
            setAllOutputs(UNDEFINED);
            return;
        }

        std::size_t address = 0;
        std::size_t bit = 0;
        for (auto pin : {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9}) {
            Tristate input = compute(pin);
            if (input == UNDEFINED) {
                setAllOutputs(UNDEFINED);
                return;
            }
            address |= (input != FALSE) << bit++;
        }

        switch (write_enabled)
        {
        case TRUE:
            writeInMemory(address);
            break;
        case FALSE:
            if (output_enabled == FALSE || output_enabled == UNDEFINED) {
                setAllOutputs(UNDEFINED);
                return;
            }
            break;
        default:
            setAllOutputs(UNDEFINED);
            return;
        }
        readMemory(address);
    }

    void Component4801::writeInMemory(std::size_t address) noexcept
    {
        setIOPinsAsInput();

        RAM::Byte byte = 0;
        std::size_t bit = 0;
        for (auto pin : {DQ0, DQ1, DQ2, DQ3, DQ4, DQ5, DQ6, DQ7}) {
            Tristate input = compute(pin);
            if (input == UNDEFINED) {
                return;
            }
            byte |= (input != FALSE) << bit++;
        }
        m_memory[address] = byte;
    }

    void Component4801::readMemory(std::size_t address) noexcept
    {
        setIOPinsAsOutput();

        constexpr std::array<std::size_t, 8> byte_output{DQ0, DQ1, DQ2, DQ3, DQ4, DQ5, DQ6, DQ7};
        const auto byte = m_memory[address];

        for (std::size_t bit = 0; bit < byte_output.size(); ++bit)
            output(byte_output.at(bit)) = get_tristate_bit(byte, bit);
    }
} // namespace nts


