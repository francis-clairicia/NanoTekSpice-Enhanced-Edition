/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>
#include <exception>

namespace nts
{
    class Exception: public std::exception
    {
    public:
        Exception(const std::string &msg) noexcept;
        ~Exception() noexcept override = default;

        const char *what() const noexcept final;

    private:
        std::string m_msg;
    };
}

#endif /* !EXCEPTION_HPP_ */
