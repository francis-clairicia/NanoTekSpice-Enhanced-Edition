/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputValueException
*/

#ifndef INPUTVALUEEXCEPTION_HPP_
#define INPUTVALUEEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class InputValueException: public Exception {
        public:
            InputValueException(const std::string &value) noexcept;
    };
}

#endif /* !INPUTVALUEEXCEPTION_HPP_ */
