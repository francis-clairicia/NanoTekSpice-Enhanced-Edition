/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** PinList
*/

#include <iostream>
#include "PinList.hpp"

nts::PinList::PinList(std::size_t nb, const pinList_t &inputs, const pinList_t &outputs):
    m_input_pins(inputs),
    m_output_pins(outputs),
    m_pins(nb)
{
    for (std::size_t pin : m_input_pins)
        m_pins.at(pin - 1) = nts::Pin::INPUT;
    for (std::size_t pin : m_output_pins)
        m_pins.at(pin - 1) = nts::Pin::OUTPUT;
}

const std::vector<std::size_t> &nts::PinList::getInputPins() const noexcept
{
    return m_input_pins;
}

const std::vector<std::size_t> &nts::PinList::getOutputPins() const noexcept
{
    return m_output_pins;
}

bool nts::PinList::hasPin(std::size_t pin) const noexcept
{
    return pin > 0 && pin <= m_pins.size();
}

void nts::PinList::dump() const noexcept
{
    std::size_t index = 0;
    for (const auto &link : m_pins) {
        std::cout << "-> Pin " << ++index << ": " << '\n';
        link.dump();
    }
}

const nts::Pin &nts::PinList::operator[](std::size_t pin) const
{
    return m_pins.at(pin - 1);
}

nts::Pin &nts::PinList::operator[](std::size_t pin)
{
    return m_pins.at(pin - 1);
}
