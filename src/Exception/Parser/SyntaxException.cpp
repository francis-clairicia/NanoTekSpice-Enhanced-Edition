/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "SyntaxException.hpp"

namespace nts
{
    SyntaxException::SyntaxException(std::size_t line, const std::string &msg) noexcept:
        ParserException("Syntax error", line, msg)
    {
    }
} // namespace nts
