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
    using componentLink_t = std::pair<IComponent *, std::size_t>;
    using internComponent_t = std::vector<std::unique_ptr<IComponent>>;
    using componentPin_t = std::vector<std::size_t>;
    using pinList_t = std::initializer_list<std::size_t>;
}

#endif /* !TYPES_HPP_ */