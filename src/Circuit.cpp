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
#include "constants.hpp"

namespace
{
    const std::unordered_map<std::string, nts::Tristate> STR_TO_TRISTATE{
        {"0", nts::FALSE},
        {"1", nts::TRUE},
        {"U", nts::UNDEFINED}
    };
} // namespace

namespace nts
{
    Circuit::Circuit() noexcept:
        m_tick{NO_TICKS}
    {
    }

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

    std::size_t Circuit::getTick() const noexcept
    {
        return m_tick;
    }

    void Circuit::setValueForNextTick(const std::string &name, const std::string &value)
    {
        auto input = STR_TO_TRISTATE.find(value);
        if (input == STR_TO_TRISTATE.end())
            throw InputValueException(value);
        setValueForNextTick(name, input->second);
    }

    void Circuit::setValueForNextTick(const std::string &name, Tristate value)
    {
        auto component = m_input_components.find(name);
        if (component == m_input_components.end())
            throw BadComponentNameException(name);
        component->second.setValue(value);
    }

    void Circuit::simulate() noexcept
    {
        if (m_tick == NO_TICKS) {
            m_tick = 0L;
        } else {
            ++m_tick;
        }
        for (auto &component : m_components)
            component.second->simulate(m_tick);
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
        auto search = m_input_components.find(name);

        if (search == m_input_components.end())
            throw BadComponentNameException(name);
        return search->second;
    }

    InputComponent &Circuit::input(const std::string &name)
    {
        auto search = m_input_components.find(name);

        if (search == m_input_components.end())
            throw BadComponentNameException(name);
        return search->second;
    }

    Circuit::InputsList Circuit::getInputs() const
    {
        InputsList list;

        for (const auto &component : m_input_components) {
            list.emplace_back(component.first, component.second);
        }
        return list;
    }

    const OutputComponent &Circuit::output(const std::string &name) const
    {
        auto search = m_output_components.find(name);

        if (search == m_output_components.end())
            throw BadComponentNameException(name);
        return search->second;
    }

    OutputComponent &Circuit::output(const std::string &name)
    {
        auto search = m_output_components.find(name);

        if (search == m_output_components.end())
            throw BadComponentNameException(name);
        return search->second;
    }

    Circuit::OutputsList Circuit::getOutputs() const
    {
        OutputsList list;

        for (const auto &component : m_output_components) {
            list.emplace_back(component.first, component.second);
        }
        return list;
    }

    const IComponent &Circuit::operator[](const std::string &key) const
    {
        auto search = m_components.find(key);

        if (search == m_components.end())
            throw BadComponentNameException(key);
        return *(search->second);
    }

    IComponent &Circuit::operator[](const std::string &key)
    {
        auto search = m_components.find(key);

        if (search == m_components.end())
            throw BadComponentNameException(key);
        return *(search->second);
    }
} // namespace nts
