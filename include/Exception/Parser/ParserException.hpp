/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ParserException
*/

#ifndef PARSEREXCEPTION_HPP_
#define PARSEREXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class ParserException: public Exception
    {
    public:
        ParserException(const std::string &error_type, std::size_t line, const std::string &error_msg) noexcept;
        ~ParserException() noexcept override = default;
    };
}

#endif /* !PARSEREXCEPTION_HPP_ */
