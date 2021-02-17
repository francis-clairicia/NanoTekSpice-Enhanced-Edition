/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** BadComponentNameException
*/

#ifndef BADCOMPONENTNAMEEXCEPTION_HPP_
#define BADCOMPONENTNAMEEXCEPTION_HPP_

#include "Exception.hpp"

namespace nts
{
    class BadComponentNameException: public Exception {
        public:
            BadComponentNameException(const std::string &component_name) noexcept;
    };
}

#endif /* !BADCOMPONENTNAMEEXCEPTION_HPP_ */
