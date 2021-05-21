/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentLinkException
*/

#include "ComponentLinkException.hpp"

namespace nts
{
    ComponentLinkException::ComponentLinkException(std::size_t line, const std::string &component_name, const std::string &error_msg) noexcept:
        ParserException("Component link error", line, "\"" + component_name + "\" -> " + error_msg)
    {
    }
} // namespace nts
