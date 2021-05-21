/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "ParserException.hpp"

namespace nts
{
    ParserException::ParserException(const std::string &error_type, std::size_t line, const std::string &error_msg) noexcept:
        Exception(error_type + " on line " + std::to_string(line) + ": " + error_msg)
    {
    }
} // namespace nts
