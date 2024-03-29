/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
