/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentTypeUnknownException
*/

#ifndef COMPONENTTYPEUNKNOWNEXCEPTION_HPP_
#define COMPONENTTYPEUNKNOWNEXCEPTION_HPP_

#include "ParserException.hpp"

namespace nts
{
    class ComponentTypeUnknownException: public ParserException
    {
    public:
        ComponentTypeUnknownException(std::size_t line, const std::string &type) noexcept;
        ~ComponentTypeUnknownException() noexcept override = default;
    };
}

#endif /* !COMPONENTTYPEUNKNOWNEXCEPTION_HPP_ */
