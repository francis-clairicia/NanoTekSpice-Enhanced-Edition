/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** FileException
*/

#ifndef FILEEXCEPTION_HPP_
#define FILEEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class FileException: public Exception
    {
    public:
        FileException(const std::string &filepath, const std::string &error_msg) noexcept;
        ~FileException() noexcept override = default;
    };
}

#endif /* !FILEEXCEPTION_HPP_ */
