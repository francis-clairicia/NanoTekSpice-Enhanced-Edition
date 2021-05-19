/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentNameOverride
*/

#include "ComponentNameOverride.hpp"

namespace nts
{
    ComponentNameOverride::ComponentNameOverride(const std::string &component_name) noexcept:
        Exception{"A component with name '" + component_name + "' already exists."}
    {
    }
} // namespace nts