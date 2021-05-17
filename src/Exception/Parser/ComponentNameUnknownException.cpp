/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "ComponentNameUnknownException.hpp"

namespace nts
{
    ComponentNameUnknownException::ComponentNameUnknownException(std::size_t line, const std::string &error_msg) noexcept:
        ParserException("Component name error", line, error_msg)
    {
    }
} // namespace nts
