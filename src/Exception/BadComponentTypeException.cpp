/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "BadComponentTypeException.hpp"

namespace nts
{
    BadComponentTypeException::BadComponentTypeException(const std::string &type) noexcept:
        Exception("Unknown component type \"" + type + "\"")
    {
    }
} // namespace nts