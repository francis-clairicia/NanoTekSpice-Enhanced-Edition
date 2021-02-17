/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "BadPinException.hpp"

nts::BadPinException::BadPinException(const std::string &component_type, std::size_t non_valid_pin) noexcept:
    Exception(component_type + " component does not have pin " + std::to_string(non_valid_pin))
{
}
