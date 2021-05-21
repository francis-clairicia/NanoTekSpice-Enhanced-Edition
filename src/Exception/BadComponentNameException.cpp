/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "BadComponentNameException.hpp"

namespace nts
{
    BadComponentNameException::BadComponentNameException(const std::string &component_name) noexcept:
        Exception("Unknown component name \"" + component_name + "\"")
    {
    }
} // namespace nts
