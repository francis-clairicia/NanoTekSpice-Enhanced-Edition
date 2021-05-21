/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** BadComponentNameException
*/

#ifndef BADCOMPONENTNAMEEXCEPTION_HPP_
#define BADCOMPONENTNAMEEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class BadComponentNameException: public Exception
    {
    public:
        BadComponentNameException(const std::string &component_name) noexcept;
        ~BadComponentNameException() noexcept override = default;
    };
}

#endif /* !BADCOMPONENTNAMEEXCEPTION_HPP_ */
