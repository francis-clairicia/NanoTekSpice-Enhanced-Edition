/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** init_vector_component
*/

#ifndef INIT_VECTOR_COMPONENT_HPP_
#define INIT_VECTOR_COMPONENT_HPP_

#include "types.hpp"

namespace nts
{
    template<typename Component>
    std::vector<InternComponent> init_vector_component(std::size_t n)
    {
        static_assert(std::is_base_of_v<IComponent, Component>);
        std::vector<InternComponent> components(n);

        if constexpr(std::is_base_of_v<IComponent, Component>) {
            for (std::size_t i = 0; i < n; ++i)
                components[i] = std::make_unique<Component>();
        }
        return components;
    }
}

#endif /* !INIT_VECTOR_COMPONENT_HPP_ */
