/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ConstComponentException
*/

#ifndef CONSTCOMPONENTEXCEPTION_HPP_
#define CONSTCOMPONENTEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class ConstComponentException: public Exception {
        public:
            ConstComponentException(const std::string &msg) noexcept;
    };
}

#endif /* !CONSTCOMPONENTEXCEPTION_HPP_ */
