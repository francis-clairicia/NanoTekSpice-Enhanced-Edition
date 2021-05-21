/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
