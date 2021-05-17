/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** PinList
*/

#ifndef PINLIST_HPP_
#define PINLIST_HPP_

#include <initializer_list>
#include "types.hpp"
#include "Pin.hpp"

namespace nts
{
    class PinList
    {
    public:
        using Initializer = std::initializer_list<std::size_t>;
        using PinMap = std::unordered_map<std::size_t, Pin>;

    public:
        PinList(std::size_t nb, PinList::Initializer inputs, PinList::Initializer outputs, bool accept_io = false);
        ~PinList() noexcept = default;

        [[nodiscard]] const ComponentPins &getInputPins() const noexcept;
        [[nodiscard]] const ComponentPins &getOutputPins() const noexcept;
        [[nodiscard]] bool hasPin(std::size_t pin) const noexcept;

        void setIOPinsAsInput() noexcept;
        void setIOPinsAsOutput() noexcept;

        void dump() const noexcept;

        const Pin &operator[](std::size_t pin) const;
        Pin &operator[](std::size_t pin);

    private:
        const ComponentPins m_input_pins;
        const ComponentPins m_output_pins;
        const ComponentPins m_both_input_and_output_pins;
        PinMap              m_pins;
    };
}

#endif /* !PINLIST_HPP_ */
