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
            m_graphical_components.emplace(name, ComponentFactory::createGraphicalComponent(type));
            IComponent &component = **(m_graphical_components.at(name));
            m_components.emplace(name, component);
            registerComponent(m_input_components, name, component);
            registerComponent(m_output_components, name, component);
        } catch (const BadComponentTypeException &) {
            Circuit::addComponent(type, name);
        }
    }
} // namespace nts


