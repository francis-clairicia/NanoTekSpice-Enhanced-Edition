/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentLinkException
*/

#ifndef COMPONENTLINKEXCEPTION_HPP_
#define COMPONENTLINKEXCEPTION_HPP_

#include "ParserException.hpp"

namespace nts
{
    class ComponentLinkException: public ParserException
    {
    public:
        ComponentLinkException(std::size_t line, const std::string &component_name, const std::string &error_msg) noexcept;
        ~ComponentLinkException() noexcept override = default;
    };
}

#endif /* !COMPONENTLINKEXCEPTION_HPP_ */
