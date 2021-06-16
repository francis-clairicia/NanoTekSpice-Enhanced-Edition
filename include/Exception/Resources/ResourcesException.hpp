/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ResourcesException
*/

#ifndef RESOURCESEXCEPTION_HPP_
#define RESOURCESEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class ResourcesException: public Exception
    {
    public:
        ResourcesException(const std::string &filepath) noexcept;
        ~ResourcesException() noexcept override = default;
    };
} // namespace nts

#endif /* !RESOURCESEXCEPTION_HPP_ */
