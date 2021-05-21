/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "FileException.hpp"

namespace nts
{
    FileException::FileException(const std::string &filepath, const std::string &error_msg) noexcept:
        Exception(filepath + ": " + error_msg)
    {
    }
} // namespace nts
