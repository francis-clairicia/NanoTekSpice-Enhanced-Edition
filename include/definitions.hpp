/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** definitions
*/

#ifndef DEFINITIONS_HPP_
#define DEFINITIONS_HPP_

#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <memory>
#include "IComponent.hpp"

namespace nts
{
    const std::unordered_map<std::string, nts::Tristate> INPUT_CONVERTER{
        {"0", nts::FALSE},
        {"1", nts::TRUE},
        {"U", nts::UNDEFINED}
    };

    using component_link_t = std::vector<std::pair<IComponent *, std::size_t>>;
    using intern_component_t = std::vector<std::unique_ptr<IComponent>>;
    using component_pin_t = std::vector<std::size_t>;
}

#endif /* !DEFINITIONS_HPP_ */
