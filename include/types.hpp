/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** types
*/

#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <initializer_list>
#include <string>
#include <vector>
#include <utility>
#include <memory>
#include "IComponent.hpp"

namespace nts
{
    using component_link_t = std::pair<IComponent *, std::size_t>;
    using component_vector_link_t = std::vector<component_link_t>;
    using intern_component_t = std::vector<std::unique_ptr<IComponent>>;
    using component_pin_t = std::vector<std::size_t>;
    using pin_list_t = std::initializer_list<std::size_t>;
}

#endif /* !TYPES_HPP_ */
