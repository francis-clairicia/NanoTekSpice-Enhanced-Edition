/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "ParserException.hpp"

nts::ParserException::ParserException(const std::string &error_type, std::size_t line, const std::string &error_msg) noexcept:
    Exception(error_type + " on line " + std::to_string(line) + ": " + error_msg)
{
}
