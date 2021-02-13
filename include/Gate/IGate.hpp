/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** IGate
*/

#ifndef IGATE_HPP_
#define IGATE_HPP_

#include "IComponent.hpp"
#include "definitions.hpp"

namespace nts
{
    class IGate {
        public:
            virtual ~IGate() = default;

            virtual nts::Tristate compute(const std::string &component_name, nts::component_link_t &links) const = 0;
    };
}

#endif /* !IGATE_HPP_ */
