/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
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
