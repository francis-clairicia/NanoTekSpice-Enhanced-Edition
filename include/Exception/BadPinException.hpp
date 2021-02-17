/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** BadPinException
*/

#ifndef BADPINEXCEPTION_HPP_
#define BADPINEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class BadPinException: public Exception {
        public:
            BadPinException(const std::string &component_type, std::size_t non_valid_pin) noexcept;
    };
}

#endif /* !BADPINEXCEPTION_HPP_ */
