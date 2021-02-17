/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "ComponentNameUnknownException.hpp"

nts::ComponentNameUnknownException::ComponentNameUnknownException(std::size_t line, const std::string &name) noexcept:
    ParserException("Component name error", line, "Unknown component name \"" + name + "\"")
{
}
