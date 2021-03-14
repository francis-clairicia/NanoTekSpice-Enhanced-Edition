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
    using pinList_t = std::initializer_list<std::size_t>;

    class PinList {
        public:
            PinList(std::size_t nb, const pinList_t &inputs, const pinList_t &outputs, bool accept_io = false);
            ~PinList() noexcept = default;

            [[nodiscard]] const nts::componentPin_t &getInputPins() const noexcept;
            [[nodiscard]] const nts::componentPin_t &getOutputPins() const noexcept;
            [[nodiscard]] bool hasPin(std::size_t pin) const noexcept;

            void setIOPinsAsInput() noexcept;
            void setIOPinsAsOutput() noexcept;

            void dump() const noexcept;

            const nts::Pin &operator[](std::size_t pin) const;
            nts::Pin &operator[](std::size_t pin);

        private:
            const nts::componentPin_t                 m_input_pins;
            const nts::componentPin_t                 m_output_pins;
            const nts::componentPin_t                 m_both_input_and_output_pins;
            std::unordered_map<std::size_t, nts::Pin> m_pins;
    };
}

#endif /* !PINLIST_HPP_ */
