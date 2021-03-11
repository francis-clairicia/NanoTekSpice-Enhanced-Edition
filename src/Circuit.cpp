/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Circuit
*/

#include <iostream>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "BadComponentTypeException.hpp"
#include "BadComponentNameException.hpp"
#include "InputValueException.hpp"

static const std::unordered_map<std::string, nts::Tristate> STR_TO_TRISTATE{
    {"0", nts::FALSE},
    {"1", nts::TRUE},
    {"U", nts::UNDEFINED}
};

static const std::unordered_map<nts::Tristate, std::string> TRISTATE_TO_STR{
    {nts::FALSE,     "0"},
    {nts::TRUE,      "1"},
    {nts::UNDEFINED, "U"}
};

nts::Circuit::Circuit() noexcept:
    m_components{}, m_input_components{}, m_output_components{}
{
}

nts::Circuit::Circuit(const std::string &filepath):
    m_components{}, m_input_components{}, m_output_components{}
{
    nts::Parser parser{filepath, *this};

    parser.parse();
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

void nts::Circuit::setValueForNextTick(const std::string &name, const std::string &value)
{
    const auto &component = m_input_components.find(name);
    if (component == m_input_components.end())
        throw nts::BadComponentNameException(name);
    const auto &input = STR_TO_TRISTATE.find(value);
    if (input == STR_TO_TRISTATE.end())
        throw nts::InputValueException(value);
    component->second.setValue(input->second);
}

void nts::Circuit::display(std::size_t tick) const noexcept
{
    std::cout << "tick: " << tick << '\n';
    std::cout << "input(s):" << '\n';
    for (const auto &component : m_input_components) {
        std::cout << std::string(2, ' ') << component.first << ": ";
        std::cout << TRISTATE_TO_STR.at(component.second.getValue()) << '\n';
    }
    std::cout << "output(s):" << '\n';
    for (const auto &component : m_output_components) {
        std::cout << std::string(2, ' ') << component.first << ": ";
        std::cout << TRISTATE_TO_STR.at(component.second.getValue()) << '\n';
    }
}

void nts::Circuit::simulate(std::size_t tick) const noexcept
{
    for (auto &component : m_components)
        component.second->simulate(tick);
}

void nts::Circuit::dump() const noexcept
{
    std::cout << "Chipsets dump:" << '\n';
    std::size_t index = 0;
    for (const auto &pair : m_components) {
        if (index++)
            std::cout << '\n';
        std::cout << "==== '" << pair.first << "' component ====" << '\n';
        pair.second->dump();
    }
}

const nts::InputComponent &nts::Circuit::input(const std::string &name) const
{
    const auto &search = m_input_components.find(name);

    if (search == m_input_components.end())
        throw nts::BadComponentNameException(name);
    return search->second;
}

nts::InputComponent &nts::Circuit::input(const std::string &name)
{
    const auto &search = m_input_components.find(name);

    if (search == m_input_components.end())
        throw nts::BadComponentNameException(name);
    return search->second;
}

const nts::OutputComponent &nts::Circuit::output(const std::string &name) const
{
    const auto &search = m_output_components.find(name);

    if (search == m_output_components.end())
        throw nts::BadComponentNameException(name);
    return search->second;
}

nts::OutputComponent &nts::Circuit::output(const std::string &name)
{
    const auto &search = m_output_components.find(name);

    if (search == m_output_components.end())
        throw nts::BadComponentNameException(name);
    return search->second;
}

const nts::IComponent &nts::Circuit::operator[](const std::string &key) const
{
    const auto &search = m_components.find(key);

    if (search == m_components.end())
        throw nts::BadComponentNameException(key);
    return *(search->second);
}

nts::IComponent &nts::Circuit::operator[](const std::string &key)
{
    const auto &search = m_components.find(key);

    if (search == m_components.end())
        throw nts::BadComponentNameException(key);
    return *(search->second);
}
