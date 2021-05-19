/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentNameOverride
*/

#ifndef COMPONENTNAMEOVERRIDE_HPP_
#define COMPONENTNAMEOVERRIDE_HPP_

#include "Exception.hpp"

namespace nts
{
    class ComponentNameOverride: public Exception
    {
    public:
        ComponentNameOverride(const std::string &component_name) noexcept;
        ~ComponentNameOverride() noexcept override = default;
    };
} // namespace nts

#endif /* !COMPONENTNAMEOVERRIDE_HPP_ */
