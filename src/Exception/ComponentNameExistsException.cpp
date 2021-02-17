/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "ComponentNameExistsException.hpp"

nts::ComponentNameExistsException::ComponentNameExistsException(std::size_t line, const std::string &name) noexcept:
    ParserException("Component name error", line, "\"" + name + "\" component already exists")
{
}
