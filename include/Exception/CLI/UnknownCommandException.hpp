/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** UnknownCommandException
*/

#ifndef UNKNOWNCOMMANDEXCEPTION_HPP_
#define UNKNOWNCOMMANDEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class UnknownCommandException: public Exception
    {
    public:
        UnknownCommandException(const std::string &command) noexcept;
        ~UnknownCommandException() noexcept override = default;
    };
} // namespace nts


#endif /* !UNKNOWNCOMMANDEXCEPTION_HPP_ */
