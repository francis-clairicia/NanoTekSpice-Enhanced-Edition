/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "BadPinException.hpp"

namespace nts
{
    BadPinException::BadPinException(const std::string &component_type, std::size_t non_valid_pin) noexcept:
        Exception(component_type + " component does not have pin " + std::to_string(non_valid_pin))
    {
    }
} // namespace nts
