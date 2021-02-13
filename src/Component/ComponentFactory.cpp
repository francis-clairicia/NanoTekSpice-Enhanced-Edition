/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentFactory
*/

#include <iostream>
#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory() noexcept:
    m_component_creator{
        {"input", []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::InputComponent>();}},
        {"output", []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::OutputComponent>();}}
    },
    m_components{},
    m_input_components{},
    m_output_components{}
{
}

nts::ComponentFactory::~ComponentFactory() noexcept
{
}

nts::ComponentFactory::ComponentFactory(const nts::ComponentFactory &other __attribute__((unused))) noexcept
{
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type) const
{
    auto search = m_component_creator.find(type);

    if (search != m_component_creator.end())
        return search->second();
    return nullptr;
}

nts::ComponentFactory::component_map_t &nts::ComponentFactory::get() noexcept
{
    return m_components;
}

nts::ComponentFactory::input_component_map_t &nts::ComponentFactory::inputs() noexcept
{
    return m_input_components;
}

nts::ComponentFactory::output_component_map_t &nts::ComponentFactory::outputs() noexcept
{
    return m_output_components;
}

void nts::ComponentFactory::dump() const noexcept
{
    std::cout << "Chipsets dump:" << std::endl;
    std::size_t index = 0;
    for (auto &pair : m_components) {
        if (index++)
            std::cout << std::endl;
        std::cout << "==== '" << pair.first << "' component ====" << std::endl;
        pair.second->dump();
    }
}

nts::ComponentFactory &nts::ComponentFactory::operator=(const nts::ComponentFactory &rhs __attribute__((unused))) noexcept
{
    return *this;
}

const std::unique_ptr<nts::IComponent> &nts::ComponentFactory::operator[](const std::string &key) const
{
    return m_components.at(key);
}

std::unique_ptr<nts::IComponent> &nts::ComponentFactory::operator[](const std::string &key)
{
    return m_components[key];
}
