/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentLinkException
*/

#include "ComponentLinkException.hpp"

nts::ComponentLinkException::ComponentLinkException(std::size_t line, const std::string &component_name, const std::string &error_msg) noexcept:
    ParserException("Component link error", line, "\"" + component_name + "\" -> " + error_msg)
{
}

