/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalCircuit
*/

#include "GraphicalCircuit.hpp"
#include "ComponentFactory.hpp"
#include "BadComponentTypeException.hpp"
#include "ComponentNameOverride.hpp"

namespace nts
{
    void GraphicalCircuit::addComponent(const std::string &type, const std::string &name)
    {
        if (hasComponent(name))
            throw ComponentNameOverride{name};

        try {
            m_components.emplace(name, ComponentFactory::createGraphicalComponent(type));
        } catch (const BadComponentTypeException &) {
            m_components.emplace(name, ComponentFactory::createComponent(type));
        }
        registerComponent(m_input_components, name, *(m_components[name]));
        registerComponent(m_output_components, name, *(m_components[name]));
        registerComponent(m_graphical_components, name, *(m_components[name]));
    }
} // namespace nts


