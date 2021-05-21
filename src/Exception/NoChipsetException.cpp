/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "NoChipsetException.hpp"

namespace nts
{
    NoChipsetException::NoChipsetException() noexcept: Exception("No chipset in the circuit")
    {
    }
} // namespace nts
