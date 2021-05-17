/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
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
