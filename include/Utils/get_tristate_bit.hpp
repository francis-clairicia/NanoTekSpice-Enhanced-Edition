/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** get_tristate_bit
*/

#ifndef GET_TRISTATE_BIT_HPP_
#define GET_TRISTATE_BIT_HPP_

#include <stdint.h>
#include "IComponent.hpp"

namespace nts
{
    constexpr Tristate get_tristate_bit(uint64_t quad_word, unsigned int bit) noexcept
    {
        return static_cast<Tristate>((quad_word & (1UL << bit)) >> bit);
    }

    constexpr Tristate get_tristate_bit(uint32_t double_word, unsigned int bit) noexcept
    {
        return static_cast<Tristate>((double_word & (1U << bit)) >> bit);
    }

    constexpr Tristate get_tristate_bit(uint16_t word, unsigned int bit) noexcept
    {
        return static_cast<Tristate>((word & (1U << bit)) >> bit);
    }

    constexpr Tristate get_tristate_bit(uint8_t byte, unsigned int bit) noexcept
    {
        return static_cast<Tristate>((byte & (1U << bit)) >> bit);
    }
} // namespace nts

#endif /* !GET_TRISTATE_BIT_HPP_ */
