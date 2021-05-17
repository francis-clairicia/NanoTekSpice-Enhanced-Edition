/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
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
