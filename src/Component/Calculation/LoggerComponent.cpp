/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** LoggerComponent
*/

#include <array>
#include "LoggerComponent.hpp"
#include "FileException.hpp"

namespace
{
    const std::string LOG_FILE{"./log.bin"};
} // namespace

namespace nts
{
    LoggerComponent::LoggerComponent():
        ACalculationComponent(ComponentType::Logger, 10, {
            BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7, CLOCK, INHIBIT
        }, {}),
        m_stream{LOG_FILE, std::ios_base::binary}
    {
        if (!m_stream)
            throw FileException(LOG_FILE, "Cannot open file");
    }

    LoggerComponent::~LoggerComponent() noexcept
    {
        m_stream.close();
    }

    void LoggerComponent::computeOutputs()
    {
        char character = 0;
        const Tristate clock = compute(CLOCK);
        const Tristate inhibit = compute(INHIBIT);
        constexpr std::array<std::size_t, 8> pins_input{BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7};
        std::array<Tristate, 8> inputs;

        if (clock == UNDEFINED || inhibit == UNDEFINED)
            return;
        if (clock == FALSE || inhibit == TRUE)
            return;

        for (std::size_t bit = 0; bit < inputs.size(); ++bit)
            inputs[bit] = compute(pins_input.at(bit));
        for (std::size_t bit = 0; bit < inputs.size(); ++bit) {
            if (inputs[bit] == UNDEFINED)
                return;
            character |= inputs[bit] << bit;
        }

        m_stream.put(character);
        m_stream.flush();
        if (m_stream.bad())
            throw FileException(LOG_FILE, "Error on writing");
    }
} // namespace nts

