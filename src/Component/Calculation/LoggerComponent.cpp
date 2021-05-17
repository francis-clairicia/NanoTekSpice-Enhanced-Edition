/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
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

    void LoggerComponent::computeOutputs(std::size_t tick)
    {
        char character = 0;
        const Tristate clock = m_pins[CLOCK].compute(tick);
        const Tristate inhibit = m_pins[INHIBIT].compute(tick);
        std::array<Tristate, 8> inputs;

        if (clock == UNDEFINED || inhibit == UNDEFINED)
            return;
        if (clock == FALSE || inhibit == TRUE)
            return;

        for (std::size_t bit = 0; bit < inputs.size(); ++bit)
            inputs[bit] = m_pins[m_pins.getInputPins().at(bit)].compute(tick);
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

