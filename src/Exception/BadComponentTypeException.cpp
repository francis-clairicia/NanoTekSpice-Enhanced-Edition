/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "BadComponentTypeException.hpp"

nts::BadComponentTypeException::BadComponentTypeException(const std::string &type) noexcept:
    Exception("Unknown component type \"" + type + "\"")
{
}

