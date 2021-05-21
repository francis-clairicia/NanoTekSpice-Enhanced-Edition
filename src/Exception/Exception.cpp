/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Exception
*/

#include "Exception.hpp"

namespace nts
{
    Exception::Exception(const std::string &msg) noexcept: m_msg(msg)
    {
    }

    const char *Exception::what() const noexcept
    {
        return m_msg.c_str();
    }
} // namespace nts
