/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** BadComponentTypeException
*/

#ifndef BADCOMPONENTTYPEEXCEPTION_HPP_
#define BADCOMPONENTTYPEEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class BadComponentTypeException: public Exception
    {
    public:
        BadComponentTypeException(const std::string &type) noexcept;
        ~BadComponentTypeException() noexcept override = default;
    };
}

#endif /* !BADCOMPONENTTYPEEXCEPTION_HPP_ */
