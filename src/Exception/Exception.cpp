/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "Exception.hpp"

nts::Exception::Exception(const std::string &msg) noexcept: m_msg(msg)
{
}

const char *nts::Exception::what() const noexcept
{
    return m_msg.c_str();
}