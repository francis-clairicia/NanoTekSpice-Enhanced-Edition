/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentNameExistsException
*/

#ifndef COMPONENTNAMEEXISTSEXCEPTION_HPP_
#define COMPONENTNAMEEXISTSEXCEPTION_HPP_

#include "ParserException.hpp"

namespace nts
{
    class ComponentNameExistsException: public ParserException
    {
        public:
            ComponentNameExistsException(std::size_t line, const std::string &name) noexcept;
            ~ComponentNameExistsException() noexcept override = default;
    };
}

#endif /* !COMPONENTNAMEEXISTSEXCEPTION_HPP_ */
