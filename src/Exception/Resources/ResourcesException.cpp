/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ResourcesException
*/

#include "ResourcesException.hpp"

namespace nts
{
    ResourcesException::ResourcesException(const std::string &filepath) noexcept:
        Exception{filepath + ": Cannot load resource."}
    {
    }
} // namespace nts
