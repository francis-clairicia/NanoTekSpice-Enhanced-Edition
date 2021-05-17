/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "InputValueException.hpp"

namespace nts
{
    InputValueException::InputValueException(const std::string &value) noexcept:
        Exception("Unknown input value \"" + value + "\"")
    {
    }
} // namespace nts
