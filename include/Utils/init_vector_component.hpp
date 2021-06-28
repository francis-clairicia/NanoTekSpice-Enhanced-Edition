/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** init_vector_component
*/

#ifndef INIT_VECTOR_COMPONENT_HPP_
#define INIT_VECTOR_COMPONENT_HPP_

#include "types.hpp"

namespace nts
{
    template<typename Component>
    InternComponentList init_vector_component(std::size_t n)
    {
        static_assert(std::is_base_of_v<IComponent, Component>);
        InternComponentList components(n);

        if constexpr(std::is_base_of_v<IComponent, Component>) {
            for (std::size_t i = 0; i < n; ++i)
                components[i] = std::make_unique<Component>();
        }
        return components;
    }
}

#endif /* !INIT_VECTOR_COMPONENT_HPP_ */
