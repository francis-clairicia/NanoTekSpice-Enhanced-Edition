/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
