/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "ComponentNameExistsException.hpp"

namespace nts
{
    ComponentNameExistsException::ComponentNameExistsException(std::size_t line, const std::string &name) noexcept:
        ParserException("Component name error", line, "\"" + name + "\" component already exists")
    {
    }
} // namespace nts
