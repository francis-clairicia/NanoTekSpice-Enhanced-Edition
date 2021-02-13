/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentFactory
*/

#include <iostream>
#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory() noexcept
{
    // m_components.emplace("input", ([]() -> std::unique_ptr<nts::IComponent> {return std::make_unique<InputComponent>();}));
    // m_components.emplace("output", ([]() -> std::unique_ptr<nts::IComponent> {return std::make_unique<InputComponent>();}));
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
    for (auto &pair : m_components) {
        std::cout << "\t-> ";
        pair.second->dump();
    }
}

nts::ComponentFactory &nts::ComponentFactory::operator=(const nts::ComponentFactory &rhs __attribute__((unused))) noexcept
{
    return *this;
}
