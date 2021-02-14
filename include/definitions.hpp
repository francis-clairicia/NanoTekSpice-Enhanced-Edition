/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** definitions
*/

#ifndef DEFINITIONS_HPP_
#define DEFINITIONS_HPP_

#include <string>
#include <array>
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

    template<std::size_t Nb>
    using component_link_t = std::array<std::pair<IComponent *, std::size_t>, Nb>;

    template<std::size_t Nb>
    using intern_component_t = std::array<std::unique_ptr<IComponent>, Nb>;

    template<std::size_t Nb>
    using component_pin_t = std::array<std::size_t, Nb>;
}

#endif /* !DEFINITIONS_HPP_ */
