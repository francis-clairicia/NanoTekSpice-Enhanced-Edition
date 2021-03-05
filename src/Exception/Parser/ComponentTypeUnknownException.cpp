/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "ComponentTypeUnknownException.hpp"

nts::ComponentTypeUnknownException::ComponentTypeUnknownException(std::size_t line, const std::string &type) noexcept:
    ParserException("Component type error", line, "Unknown component type \"" + type + "\"")
{
}
