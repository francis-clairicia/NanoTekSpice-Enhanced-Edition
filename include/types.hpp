/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** types
*/

#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <vector>
#include <memory>
#include "IComponent.hpp"
#include "ComponentType.hpp"

namespace nts
{
    using InternComponent = std::unique_ptr<IComponent>;
    using InternComponentList = std::vector<InternComponent>;
    using ComponentPins = std::vector<std::size_t>;
}

#endif /* !TYPES_HPP_ */
