/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** PinList
*/

#include <algorithm>
#include <iostream>
#include "PinList.hpp"

template<typename T>
static std::vector<T> get_intermediate(std::vector<T> a, std::vector<T> b)
{
    std::vector<T> a_inter_b;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(a_inter_b));
    return a_inter_b;
}

nts::PinList::PinList(std::size_t nb, const pinList_t &inputs, const pinList_t &outputs):
    m_input_pins(inputs),
    m_output_pins(outputs),
    m_pins{}
{
    nts::componentPin_t both_input_and_output_pins(get_intermediate(m_input_pins, m_output_pins));

    for (std::size_t pin = 1; pin <= nb; ++pin) {
        if (std::find(both_input_and_output_pins.begin(), both_input_and_output_pins.end(), pin) != both_input_and_output_pins.end()) {
            m_pins.emplace(pin, nts::Pin(nts::Pin::BIDIRECTIONAL));
        } else if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
            m_pins.emplace(pin, nts::Pin(nts::Pin::UNIDIRECTIONAL, nts::Pin::INPUT));
        } else if (std::find(m_output_pins.begin(), m_output_pins.end(), pin) != m_output_pins.end()) {
            m_pins.emplace(pin, nts::Pin(nts::Pin::UNIDIRECTIONAL, nts::Pin::OUTPUT));
        } else {
            m_pins.emplace(pin, nts::Pin(nts::Pin::UNIDIRECTIONAL, nts::Pin::NONE));
        }
    }
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
    for (std::size_t index = 1; index <= m_pins.size(); ++index) {
        std::cout << "-> Pin " << index << ": " << '\n';
        m_pins.at(index).dump();
    }
}

const nts::Pin &nts::PinList::operator[](std::size_t pin) const
{
    return m_pins.at(pin);
}

nts::Pin &nts::PinList::operator[](std::size_t pin)
{
    return m_pins.at(pin);
}
