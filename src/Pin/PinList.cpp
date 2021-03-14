/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** PinList
*/

#include <algorithm>
#include <iostream>
#include "PinList.hpp"
#include "Exception.hpp"

template<template <typename, typename...> typename Container, typename Type, typename... Args>
static Container<Type, Args...> get_intermediate(Container<Type, Args...> a, Container<Type, Args...> b)
{
    Container<Type, Args...> a_inter_b;

    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b));
    std::set_intersection(std::begin(a), std::end(a), std::begin(b), std::end(b), std::back_inserter(a_inter_b));
    return a_inter_b;
}

nts::PinList::PinList(std::size_t nb, const pinList_t &inputs, const pinList_t &outputs, bool accept_io):
    m_input_pins(inputs),
    m_output_pins(outputs),
    m_both_input_and_output_pins(get_intermediate(m_input_pins, m_output_pins)),
    m_pins{}
{
    if (!accept_io && !m_both_input_and_output_pins.empty())
        throw nts::Exception("This component cannot have pins which are inputs and outputs at the same time");
    for (std::size_t pin = 1; pin <= nb; ++pin) {
        if (std::find(m_both_input_and_output_pins.begin(), m_both_input_and_output_pins.end(), pin) != m_both_input_and_output_pins.end()) {
            m_pins.emplace(pin, nts::Pin(nts::Pin::BIDIRECTIONAL, nts::Pin::NONE));
        } else if (std::find(m_input_pins.begin(), m_input_pins.end(), pin) != m_input_pins.end()) {
            m_pins.emplace(pin, nts::Pin(nts::Pin::UNIDIRECTIONAL, nts::Pin::INPUT));
        } else if (std::find(m_output_pins.begin(), m_output_pins.end(), pin) != m_output_pins.end()) {
            m_pins.emplace(pin, nts::Pin(nts::Pin::UNIDIRECTIONAL, nts::Pin::OUTPUT));
        } else {
            m_pins.emplace(pin, nts::Pin(nts::Pin::UNIDIRECTIONAL, nts::Pin::NONE));
        }
    }
}

const nts::componentPin_t &nts::PinList::getInputPins() const noexcept
{
    return m_input_pins;
}

const nts::componentPin_t &nts::PinList::getOutputPins() const noexcept
{
    return m_output_pins;
}

void nts::PinList::setIOPinsAsInput() noexcept
{
    for (std::size_t pin : m_both_input_and_output_pins)
        m_pins.at(pin).computeAsInput();
}

void nts::PinList::setIOPinsAsOutput() noexcept
{
    for (std::size_t pin : m_both_input_and_output_pins)
        m_pins.at(pin).computeAsOutput();
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
