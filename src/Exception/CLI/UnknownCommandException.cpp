/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** UnknownCommandException
*/

#include "UnknownCommandException.hpp"

namespace nts
{
    UnknownCommandException::UnknownCommandException(const std::string &command) noexcept:
        Exception{"Unknown command \"" + command + "\""}
    {
    }
} // namespace nts


