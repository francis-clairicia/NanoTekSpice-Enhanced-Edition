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
            m_graphical_components.at(name)->setName(name);
            IComponent &component = **(m_graphical_components.at(name));
            m_components.emplace(name, component);

            InputComponent *input = dynamic_cast<InputComponent *>(&component);
            if (input)
                m_input_components.emplace(name, *input);

            OutputComponent *output = dynamic_cast<OutputComponent *>(&component);
            if (output)
                m_output_components.emplace(name, *output);
        } catch (const BadComponentTypeException &) {
            Circuit::addComponent(type, name);
        }
    }
} // namespace nts


