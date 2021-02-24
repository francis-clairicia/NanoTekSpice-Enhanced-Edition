/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** LoggerComponent
*/

#include "LoggerComponent.hpp"
#include "FileException.hpp"

static const std::string LOG_FILE{"./log.bin"};

nts::LoggerComponent::LoggerComponent():
    ACalculationComponent(ComponentType::Logger, 10, {
        BIT0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7, CLOCK, INHIBIT
    }, {})
{
}

nts::LoggerComponent::~LoggerComponent() noexcept
{
}

void nts::LoggerComponent::computeOutputs()
{
    char character = 0;
    nts::Tristate clock = compute(CLOCK);
    nts::Tristate inhibit = compute(INHIBIT);
    nts::Tristate input;

    if (clock == nts::UNDEFINED || inhibit == nts::UNDEFINED)
        return;
    if (clock == nts::FALSE || inhibit == nts::TRUE)
        return;
    
    for (std::size_t bit = 0; bit < 8; ++bit) {
        input = compute(m_input_pins[bit]);
        if (input == nts::UNDEFINED)
            return;
        character |= input << bit;
    }
    
    std::ofstream output_stream{LOG_FILE, std::ios_base::out | std::ios_base::app | std::ios_base::binary};

    if (!output_stream)
        throw FileException(LOG_FILE, "Cannot open file");
    output_stream.put(character);
    if (output_stream.bad())
        throw FileException(LOG_FILE, "Error on writing");
    output_stream.close();
}
