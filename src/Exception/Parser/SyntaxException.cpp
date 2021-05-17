/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
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
