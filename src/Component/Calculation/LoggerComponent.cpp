/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** LoggerComponent
*/

#include <array>
#include "LoggerComponent.hpp"
#include "FileException.hpp"

static const std::string LOG_FILE{"./log.bin"};

nts::LoggerComponent::LoggerComponent():
    ACalculationComponent(ComponentType::Logger, 10, {
        BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7, CLOCK, INHIBIT
    }, {}),
    m_stream{LOG_FILE, std::ios_base::out | std::ios_base::binary}
{
    if (!m_stream)
        throw FileException(LOG_FILE, "Cannot open file");
}

nts::LoggerComponent::~LoggerComponent() noexcept
{
    m_stream.close();
}

void nts::LoggerComponent::computeOutputs()
{
    char character = 0;
    nts::Tristate clock = compute(CLOCK);
    nts::Tristate inhibit = compute(INHIBIT);
    std::array<nts::Tristate, 8> inputs;

    if (clock == nts::UNDEFINED || inhibit == nts::UNDEFINED)
        return;
    if (clock == nts::FALSE || inhibit == nts::TRUE)
        return;

    for (std::size_t bit = 0; bit < inputs.size(); ++bit)
        inputs[bit] = compute(m_input_pins[bit]);
    for (std::size_t bit = 0; bit < inputs.size(); ++bit) {
        if (inputs[bit] == nts::UNDEFINED)
            return;
        character |= inputs[bit] << bit;
    }

    m_stream.put(character);
    m_stream.flush();
    if (m_stream.bad())
        throw FileException(LOG_FILE, "Error on writing");
}