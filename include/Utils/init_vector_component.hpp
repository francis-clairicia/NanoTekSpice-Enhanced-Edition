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
    void init_vector_component(std::vector<std::unique_ptr<IComponent>> &components, const std::size_t &n)
    {
        for (std::size_t i = 0; i < n; ++i)
            components.push_back(std::make_unique<Component>());
    }
}

#endif /* !INIT_VECTOR_COMPONENT_HPP_ */
