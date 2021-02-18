/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentNameUnknownException
*/

#ifndef COMPONENTNAMEUNKNOWNEXCEPTION_HPP_
#define COMPONENTNAMEUNKNOWNEXCEPTION_HPP_

#include "ParserException.hpp"

namespace nts
{
    class ComponentNameUnknownException: public ParserException {
        public:
            ComponentNameUnknownException(std::size_t line, const std::string &error_msg) noexcept;
    };
}

#endif /* !COMPONENTNAMEUNKNOWNEXCEPTION_HPP_ */
