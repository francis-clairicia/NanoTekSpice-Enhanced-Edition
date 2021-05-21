/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
