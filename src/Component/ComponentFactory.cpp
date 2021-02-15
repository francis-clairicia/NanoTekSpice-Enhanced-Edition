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

void nts::ComponentFactory::addComponent(const std::string &type, const std::string &name)
{
    m_components[name] = createComponent(type);

    InputComponent *input = dynamic_cast<InputComponent *>(m_components[name].get());
    if (input)
        m_input_components.emplace(name, reinterpret_cast<std::unique_ptr<InputComponent> &>(m_components[name]));
    
    OutputComponent *output = dynamic_cast<OutputComponent *>(m_components[name].get());
    if (output)
        m_output_components.emplace(name, reinterpret_cast<std::unique_ptr<OutputComponent> &>(m_components[name]));
}

nts::ComponentFactory::component_map_t &nts::ComponentFactory::get() noexcept
{
    return m_components;
}

const nts::ComponentFactory::input_component_map_t &nts::ComponentFactory::inputs() const noexcept
{
    return m_input_components;
}

nts::InputComponent &nts::ComponentFactory::inputs(const std::string &name) const
{
    auto search = m_input_components.find(name);

    if (search == m_input_components.end())
        throw nts::BadComponentName(name);
    return *(search->second.get());
}

const nts::ComponentFactory::output_component_map_t &nts::ComponentFactory::outputs() const noexcept
{
    return m_output_components;
}

nts::OutputComponent &nts::ComponentFactory::outputs(const std::string &name) const
{
    auto search = m_output_components.find(name);

    if (search == m_output_components.end())
        throw nts::BadComponentName(name);
    return *(search->second.get());
}

void nts::ComponentFactory::display(std::size_t tick) const noexcept
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &component : m_input_components)
        std::cout << std::string(2, ' ') << component.first << ": " << component.second->getValueAsString() << std::endl;
    std::cout << "output(s):" << std::endl;
    for (auto &component : m_output_components)
        std::cout << std::string(2, ' ') << component.first << ": " << component.second->getValueAsString() << std::endl;
}

void nts::ComponentFactory::simulate(std::size_t tick) const
{
    for (auto &component : m_components)
        component.second->simulate(tick);
    for (auto &component : m_output_components) {
        component.second->compute(1);
    }
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
    auto search = m_components.find(key);

    if (search == m_components.end())
        throw nts::BadComponentName(key);
    return search->second;
}
