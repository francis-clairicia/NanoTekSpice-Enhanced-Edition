/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** InputValueException
*/

#ifndef INPUTVALUEEXCEPTION_HPP_
#define INPUTVALUEEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class InputValueException: public Exception
    {
    public:
        InputValueException(const std::string &value) noexcept;
        ~InputValueException() noexcept override = default;
    };
}

#endif /* !INPUTVALUEEXCEPTION_HPP_ */
