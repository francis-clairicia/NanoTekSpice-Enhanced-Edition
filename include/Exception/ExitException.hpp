/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ExitException
*/

#ifndef EXITEXCEPTION_HPP_
#define EXITEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class ExitException: public Exception {
        public:
            ExitException() noexcept;
    };
}

#endif /* !EXITEXCEPTION_HPP_ */
