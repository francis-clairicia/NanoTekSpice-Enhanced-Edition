/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** init_vector_component
*/

#ifndef INIT_VECTOR_COMPONENT_HPP_
#define INIT_VECTOR_COMPONENT_HPP_

#include <vector>
#include <memory>
#include "IComponent.hpp"

namespace nts
{
    template<typename Component>
    std::vector<std::unique_ptr<IComponent>> init_vector_component(std::size_t n)
    {
        std::vector<std::unique_ptr<IComponent>> components;

        for (std::size_t i = 0; i < n; ++i)
            components.push_back(std::make_unique<Component>());
        return components;
    }
}

#endif /* !INIT_VECTOR_COMPONENT_HPP_ */
