/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "ComponentTypeUnknownException.hpp"

namespace nts
{
    ComponentTypeUnknownException::ComponentTypeUnknownException(std::size_t line, const std::string &type) noexcept:
        ParserException("Component type error", line, "Unknown component type \"" + type + "\"")
    {
    }
} // namespace nts
