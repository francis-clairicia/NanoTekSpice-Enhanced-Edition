/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Circuit
*/

#include <iostream>
#include "Circuit.hpp"
#include "BadComponentTypeException.hpp"
#include "BadComponentNameException.hpp"
#include "InputValueException.hpp"

static const std::unordered_map<std::string, nts::Tristate> TRISTATE_CONVERTER{
    {"0", nts::FALSE},
    {"1", nts::TRUE},
    {"U", nts::UNDEFINED}
};

nts::Circuit::Circuit() noexcept:
    m_components{}, m_input_components{}, m_output_components{}
{
}

nts::Circuit::~Circuit() noexcept
{
}

nts::Circuit::Circuit(const nts::Circuit &other __attribute__((unused))) noexcept
{
}

void nts::Circuit::addComponent(const std::string &type, const std::string &name)
{
    m_components[name] = m_factory.createComponent(type);

    InputComponent *input = dynamic_cast<InputComponent *>(m_components[name].get());
    if (input)
        m_input_components.emplace(name, *input);
    
    OutputComponent *output = dynamic_cast<OutputComponent *>(m_components[name].get());
    if (output)
        m_output_components.emplace(name, *output);
}

bool nts::Circuit::hasComponent(const std::string &name) const noexcept
{
    return m_components.find(name) != m_components.end();
}

bool nts::Circuit::empty() const noexcept
{
    return m_components.empty();
}

const nts::Circuit::inputComponentMap_t &nts::Circuit::inputs() const noexcept
{
    return m_input_components;
}

nts::InputComponent &nts::Circuit::inputs(const std::string &name) const
{
    const auto &search = m_input_components.find(name);

    if (search == m_input_components.end())
        throw nts::BadComponentNameException(name);
    return (search->second);
}

const nts::Circuit::outputComponentMap_t &nts::Circuit::outputs() const noexcept
{
    return m_output_components;
}

nts::OutputComponent &nts::Circuit::outputs(const std::string &name) const
{
    const auto &search = m_output_components.find(name);

    if (search == m_output_components.end())
        throw nts::BadComponentNameException(name);
    return (search->second);
}

void nts::Circuit::setValueForNextTick(const std::string &name, const std::string &value)
{
    if (m_input_components.find(name) == m_input_components.end())
        throw nts::BadComponentNameException(name);
    const auto &search = TRISTATE_CONVERTER.find(value);
    if (search == TRISTATE_CONVERTER.end())
        throw nts::InputValueException(value);
    m_value_to_set[name] = value;
}

void nts::Circuit::display(std::size_t tick) const noexcept
{
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (const auto &component : m_input_components)
        std::cout << std::string(2, ' ') << component.first << ": " << component.second.getValueAsString() << std::endl;
    std::cout << "output(s):" << std::endl;
    for (const auto &component : m_output_components)
        std::cout << std::string(2, ' ') << component.first << ": " << component.second.getValueAsString() << std::endl;
}

void nts::Circuit::simulate(std::size_t tick)
{
    for (auto &component : m_components)
        component.second->simulate(tick);
    for (const auto &pair : m_value_to_set)
        m_input_components.at(pair.first).setValue(TRISTATE_CONVERTER.at(pair.second));
    m_value_to_set.clear();
    for (auto &component : m_output_components)
        component.second.compute(1);
}

void nts::Circuit::dump() const noexcept
{
    std::cout << "Chipsets dump:" << std::endl;
    std::size_t index = 0;
    for (const auto &pair : m_components) {
        if (index++)
            std::cout << std::endl;
        std::cout << "==== '" << pair.first << "' component ====" << std::endl;
        pair.second->dump();
    }
}

nts::Circuit &nts::Circuit::operator=(const nts::Circuit &rhs __attribute__((unused))) noexcept
{
    return *this;
}

const std::unique_ptr<nts::IComponent> &nts::Circuit::operator[](const std::string &key) const
{
    const auto &search = m_components.find(key);

    if (search == m_components.end())
        throw nts::BadComponentNameException(key);
    return search->second;
}
