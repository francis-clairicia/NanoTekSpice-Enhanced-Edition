/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SyntaxException
*/

#ifndef SYNTAXEXCEPTION_HPP_
#define SYNTAXEXCEPTION_HPP_

#include "ParserException.hpp"

namespace nts
{
    class SyntaxException: public ParserException
    {
    public:
        SyntaxException(std::size_t line, const std::string &msg) noexcept;
        ~SyntaxException() noexcept override = default;
    };
}

#endif /* !SYNTAXEXCEPTION_HPP_ */
