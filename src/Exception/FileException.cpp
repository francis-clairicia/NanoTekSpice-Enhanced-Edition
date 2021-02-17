/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "FileException.hpp"

nts::FileException::FileException(const std::string &filepath, const std::string &error_msg) noexcept:
    Exception(filepath + ": " + error_msg)
{
}
