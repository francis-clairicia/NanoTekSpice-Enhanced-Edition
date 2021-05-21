/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentNameUnknownException
*/

#ifndef COMPONENTNAMEUNKNOWNEXCEPTION_HPP_
#define COMPONENTNAMEUNKNOWNEXCEPTION_HPP_

#include "ParserException.hpp"

namespace nts
{
    class ComponentNameUnknownException: public ParserException
    {
    public:
        ComponentNameUnknownException(std::size_t line, const std::string &error_msg) noexcept;
        ~ComponentNameUnknownException() noexcept override = default;
    };
}

#endif /* !COMPONENTNAMEUNKNOWNEXCEPTION_HPP_ */
