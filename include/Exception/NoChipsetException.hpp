/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** NoChipsetException
*/

#ifndef NOCHIPSETEXCEPTION_HPP_
#define NOCHIPSETEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class NoChipsetException: public Exception
    {
    public:
        NoChipsetException() noexcept;
        ~NoChipsetException() noexcept override = default;
    };
}

#endif /* !NOCHIPSETEXCEPTION_HPP_ */
