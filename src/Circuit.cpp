/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Circuit
*/

#include <iostream>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "ComponentFactory.hpp"
#include "BadComponentTypeException.hpp"
#include "BadComponentNameException.hpp"
#include "ComponentNameOverride.hpp"
#include "InputValueException.hpp"

namespace
{
    const std::unordered_map<std::string, nts::Tristate> STR_TO_TRISTATE{
        {"0", nts::FALSE},
        {"1", nts::TRUE},
        {"U", nts::UNDEFINED}
    };

    const std::unordered_map<nts::Tristate, std::string> TRISTATE_TO_STR{
        {nts::FALSE,     "0"},
        {nts::TRUE,      "1"},
        {nts::UNDEFINED, "U"}
    };
} // namespace

namespace nts
{
    void Circuit::addComponent(const std::string &type, const std::string &name)
    {
        if (hasComponent(name))
            throw ComponentNameOverride{name};

        m_components.emplace(name, ComponentFactory::createComponent(type));

        InputComponent *input = dynamic_cast<InputComponent *>(m_components[name].get());
        if (input)
            m_input_components.emplace(name, *input);

        OutputComponent *output = dynamic_cast<OutputComponent *>(m_components[name].get());
        if (output)
            m_output_components.emplace(name, *output);
    }

    bool Circuit::hasComponent(const std::string &name) const noexcept
    {
        return m_components.find(name) != m_components.end();
    }

    bool Circuit::empty() const noexcept
    {
        return m_components.empty();
    }

    void Circuit::setValueForNextTick(const std::string &name, const std::string &value)
    {
        const auto &component = m_input_components.find(name);
        if (component == m_input_components.end())
            throw BadComponentNameException(name);
        const auto &input = STR_TO_TRISTATE.find(value);
        if (input == STR_TO_TRISTATE.end())
            throw InputValueException(value);
        component->second.setValue(input->second);
    }

    void Circuit::display(std::size_t tick) const noexcept
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

    void Circuit::simulate(std::size_t tick) const noexcept
    {
        for (auto &component : m_components)
            component.second->simulate(tick);
    }

    void Circuit::dump() const noexcept
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

    const InputComponent &Circuit::input(const std::string &name) const
    {
        const auto &search = m_input_components.find(name);

        if (search == m_input_components.end())
            throw BadComponentNameException(name);
        return search->second;
    }

    InputComponent &Circuit::input(const std::string &name)
    {
        const auto &search = m_input_components.find(name);

        if (search == m_input_components.end())
            throw BadComponentNameException(name);
        return search->second;
    }

    const OutputComponent &Circuit::output(const std::string &name) const
    {
        const auto &search = m_output_components.find(name);

        if (search == m_output_components.end())
            throw BadComponentNameException(name);
        return search->second;
    }

    OutputComponent &Circuit::output(const std::string &name)
    {
        const auto &search = m_output_components.find(name);

        if (search == m_output_components.end())
            throw BadComponentNameException(name);
        return search->second;
    }

    const IComponent &Circuit::operator[](const std::string &key) const
    {
        const auto &search = m_components.find(key);

        if (search == m_components.end())
            throw BadComponentNameException(key);
        return *(search->second);
    }

    IComponent &Circuit::operator[](const std::string &key)
    {
        const auto &search = m_components.find(key);

        if (search == m_components.end())
            throw BadComponentNameException(key);
        return *(search->second);
    }
} // namespace nts
