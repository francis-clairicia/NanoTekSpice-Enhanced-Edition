/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
