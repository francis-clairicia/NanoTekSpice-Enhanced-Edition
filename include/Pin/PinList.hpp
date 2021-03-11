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
            PinList(std::size_t nb, const pinList_t &inputs, const pinList_t &outputs);
            ~PinList() noexcept = default;

            [[nodiscard]] const std::vector<std::size_t> &getInputPins() const noexcept;
            [[nodiscard]] const std::vector<std::size_t> &getOutputPins() const noexcept;
            [[nodiscard]] bool hasPin(std::size_t pin) const noexcept;

            void dump() const noexcept;

            const nts::Pin &operator[](std::size_t pin) const;
            nts::Pin &operator[](std::size_t pin);

        private:
            const std::vector<std::size_t> m_input_pins;
            const std::vector<std::size_t> m_output_pins;
            std::vector<nts::Pin>          m_pins;
    };
}

#endif /* !PINLIST_HPP_ */
