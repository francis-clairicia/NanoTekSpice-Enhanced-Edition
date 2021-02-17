/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentTypeUnknownException
*/

#ifndef COMPONENTTYPEUNKNOWNEXCEPTION_HPP_
#define COMPONENTTYPEUNKNOWNEXCEPTION_HPP_

#include "ParserException.hpp"

namespace nts
{
    class ComponentTypeUnknownException: public ParserException {
        public:
            ComponentTypeUnknownException(std::size_t line, const std::string &type) noexcept;
    };
}

#endif /* !COMPONENTTYPEUNKNOWNEXCEPTION_HPP_ */
