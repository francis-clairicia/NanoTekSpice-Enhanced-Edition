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
#include <memory>
#include "IComponent.hpp"

namespace nts
{
    struct Link
    {
        IComponent *component;
        std::size_t pin;
    };

    using internComponent_t = std::vector<std::unique_ptr<IComponent>>;
    using componentPin_t = std::vector<std::size_t>;
    using pinList_t = std::initializer_list<std::size_t>;
}

#endif /* !TYPES_HPP_ */
