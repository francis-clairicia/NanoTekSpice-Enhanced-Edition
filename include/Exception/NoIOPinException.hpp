/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** NoIOPinException
*/

#ifndef NOIOPINEXCEPTION_HPP_
#define NOIOPINEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class NoIOPinException: public Exception
    {
    public:
        NoIOPinException(const std::string &component_name) noexcept;
        ~NoIOPinException() noexcept override = default;
    };
} // namespace nts


#endif /* !NOIOPINEXCEPTION_HPP_ */
