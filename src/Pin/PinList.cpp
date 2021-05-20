/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** PinList
*/

#include <algorithm>
#include <iostream>
#include "PinList.hpp"
#include "BadPinException.hpp"
#include "NoIOPinException.hpp"
#include "constants.hpp"

namespace
{
    template<template <typename, typename...> typename Container, typename Type, typename... Args>
    Container<Type, Args...> get_intermediate(Container<Type, Args...> a, Container<Type, Args...> b)
    {
        Container<Type, Args...> a_inter_b;

        std::sort(std::begin(a), std::end(a));
        std::sort(std::begin(b), std::end(b));
        std::set_intersection(std::begin(a), std::end(a), std::begin(b), std::end(b), std::back_inserter(a_inter_b));
        return a_inter_b;
    }

    template<typename T, typename... Args>
    bool vector_contains(const std::vector<T, Args...> &vector, const T &value)
    {
        return std::find(std::begin(vector), std::end(vector), value) != std::end(vector);
    }
} // namespace

namespace nts
{
    PinList::PinList(ComponentType owner, std::size_t nb, Initializer inputs, Initializer outputs, bool accept_io):
        m_owner{owner},
        m_input_pins{inputs},
        m_output_pins{outputs},
        m_both_input_and_output_pins{get_intermediate(m_input_pins, m_output_pins)},
        m_actual_tick{NO_TICKS}
    {
        if (!accept_io && !m_both_input_and_output_pins.empty())
            throw NoIOPinException{COMPONENT_TYPE_AS_STRING.at(m_owner)};
        for (std::size_t pin = 1; pin <= nb; ++pin) {
            if (vector_contains(m_both_input_and_output_pins, pin)) {
                m_pins.emplace(pin, Pin{Pin::BIDIRECTIONAL, Pin::OUTPUT});
            } else if (vector_contains(m_input_pins, pin)) {
                m_pins.emplace(pin, Pin{Pin::UNIDIRECTIONAL, Pin::INPUT});
            } else if (vector_contains(m_output_pins, pin)) {
                m_pins.emplace(pin, Pin{Pin::UNIDIRECTIONAL, Pin::OUTPUT});
            } else {
                m_pins.emplace(pin, Pin{Pin::UNIDIRECTIONAL, Pin::NONE});
            }
            m_input_values.emplace(pin, UNDEFINED);
            m_output_values.emplace(pin, UNDEFINED);
        }
    }

    const ComponentPins &PinList::getInputPins() const noexcept
    {
        return m_input_pins;
    }

    const ComponentPins &PinList::getOutputPins() const noexcept
    {
        return m_output_pins;
    }

    bool PinList::hasPin(std::size_t pin) const noexcept
    {
        return pin > 0 && pin <= m_pins.size();
    }

    const Tristate &PinList::input(std::size_t pin) const
    {
        checkPin(m_input_pins, pin);
        return m_input_values.at(pin);
    }

    Tristate &PinList::input(std::size_t pin)
    {
        checkPin(m_input_pins, pin);
        return m_input_values.at(pin);
    }

    const Tristate &PinList::output(std::size_t pin) const
    {
        checkPin(m_output_pins, pin);
        return m_output_values.at(pin);
    }

    Tristate &PinList::output(std::size_t pin)
    {
        checkPin(m_output_pins, pin);
        return m_output_values.at(pin);
    }

    bool PinList::updateInputs(std::size_t tick)
    {
        if (m_actual_tick != tick) {
            m_actual_tick = tick;
            for (auto pin_idx : m_input_pins) {
                Pin &pin = m_pins.at(pin_idx);
                m_input_values[pin_idx] = pin.computeExternalLinks(tick);
            }
            return true;
        }
        return false;
    }

    Tristate PinList::compute(std::size_t pin)
    {
        checkPin(pin);
        Pin &p = m_pins.at(pin);
        if (p.isOutput()) {
            if (p.hasInternalLinks()) {
                const Locker locker{*this};
                return p.computeInternalLinks(m_actual_tick);
            }
            return m_output_values.at(pin);
        }
        if (p.isInput()) {
            if (!isLocked())
                return FALSE;
            return m_input_values.at(pin);
        }
        return UNDEFINED;
    }

    Tristate PinList::computeInternal(IComponent &component, std::size_t pin)
    {
        const Locker locker{*this};

        component.simulate(m_actual_tick);
        return component.compute(pin);
    }

    void PinList::setAllOutputs(Tristate v) noexcept
    {
        for (auto pin_idx : m_output_pins) {
            m_output_values.at(pin_idx) = v;
        }
    }

    void PinList::setIOPinsAsInput() noexcept
    {
        for (auto pin : m_both_input_and_output_pins) {
            m_pins.at(pin).computeAsInput();
        }
    }

    void PinList::setIOPinsAsOutput() noexcept
    {
        for (auto pin : m_both_input_and_output_pins) {
            m_pins.at(pin).computeAsOutput();
        }
    }

    void PinList::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        checkPin(pin);
        m_pins.at(pin).setLinkWithExternalComponent(other, otherPin);
    }

    void PinList::setLinkInternal(IComponent &owner, std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        checkPin(pin);
        Pin &p = m_pins.at(pin);
        if (p.isInput() || p.isBidirectional()) {
            other.setLink(otherPin, owner, pin);
        } else {
            p.setLinkWithInternalComponent(other, otherPin);
        }
    }

    bool PinList::isLocked() const noexcept
    {
        return m_locked;
    }

    void PinList::lock() noexcept
    {
        m_locked = true;
    }

    void PinList::unlock() noexcept
    {
        m_locked = false;
    }

    void PinList::dump() const noexcept
    {
        for (std::size_t index = 1; index <= m_pins.size(); ++index) {
            std::cout << "-> Pin " << index << ": " << '\n';
            m_pins.at(index).dump();
        }
    }

    void PinList::checkPin(std::size_t pin) const
    {
        if (!hasPin(pin))
            throw BadPinException{COMPONENT_TYPE_AS_STRING.at(m_owner), pin};
    }

    void PinList::checkPin(const std::vector<std::size_t> &list, std::size_t pin) const
    {
        if (!vector_contains(list, pin))
            throw BadPinException{COMPONENT_TYPE_AS_STRING.at(m_owner), pin};
    }

    PinList::Locker::Locker(PinList &pin_list) noexcept:
        m_pin_list{pin_list},
        m_already_locked{pin_list.isLocked()}
    {
        if (!m_already_locked)
            m_pin_list.lock();
    }

    PinList::Locker::~Locker() noexcept
    {
        if (!m_already_locked)
            m_pin_list.unlock();
    }
} // namespace nts
