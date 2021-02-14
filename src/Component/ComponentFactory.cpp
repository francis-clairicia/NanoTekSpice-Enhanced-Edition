/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentFactory
*/

#include <iostream>
#include "ComponentFactory.hpp"
#include "ClockComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"
#include "Component4001.hpp"
#include "Component4008.hpp"
#include "Component4011.hpp"
#include "Component4013.hpp"
#include "Component4030.hpp"
#include "Component4069.hpp"
#include "Component4071.hpp"
#include "Component4081.hpp"
#include "Exception.hpp"

const std::unordered_map<std::string, nts::ComponentFactory::component_creator_t> nts::ComponentFactory::COMPONENT_CREATOR{
    {"input",  []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::InputComponent>();}},
    {"clock",  []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::ClockComponent>();}},
    {"true",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::TrueComponent>();}},
    {"false",  []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::FalseComponent>();}},
    {"output", []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::OutputComponent>();}},
    {"4001",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4001>();}},
    {"4008",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4008>();}},
    {"4011",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4011>();}},
    {"4013",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4013>();}},
    {"4030",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4030>();}},
    {"4069",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4069>();}},
    {"4071",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4071>();}},
    {"4081",   []() -> std::unique_ptr<nts::IComponent> {return std::make_unique<nts::Component4081>();}},
};

nts::ComponentFactory::ComponentFactory() noexcept:
    m_components{}, m_input_components{}, m_output_components{}
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
    auto search = nts::ComponentFactory::COMPONENT_CREATOR.find(type);

    if (search == nts::ComponentFactory::COMPONENT_CREATOR.end())
        throw nts::BadComponentTypeException(type);
    return search->second();
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
