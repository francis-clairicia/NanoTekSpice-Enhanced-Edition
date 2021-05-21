/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** BadPinException
*/

#ifndef BADPINEXCEPTION_HPP_
#define BADPINEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class BadPinException: public Exception
    {
    public:
        BadPinException(const std::string &component_type, std::size_t non_valid_pin) noexcept;
        ~BadPinException() noexcept override = default;
    };
}

#endif /* !BADPINEXCEPTION_HPP_ */
