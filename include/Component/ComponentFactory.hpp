/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <string>
#include <memory>
#include <unordered_map>
#include <map>
#include "IComponent.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"

namespace nts
{
    class ComponentFactory {
        public:
            typedef std::unique_ptr<nts::IComponent> (*component_creator_t)();
            typedef std::map<std::string, std::unique_ptr<nts::IComponent>> component_map_t;
            typedef std::map<std::string, std::unique_ptr<nts::InputComponent> &> input_component_map_t;
            typedef std::map<std::string, std::unique_ptr<nts::OutputComponent> &> output_component_map_t;

        public:
            static const std::unordered_map<std::string, component_creator_t> COMPONENT_CREATOR;

        public:
            ComponentFactory() noexcept;
            ComponentFactory(const nts::ComponentFactory &other) noexcept;
            ~ComponentFactory() noexcept;

            std::unique_ptr<nts::IComponent> createComponent(const std::string &type) const;
            void addComponent(const std::string &type, const std::string &name);

            component_map_t &get() noexcept;
            const input_component_map_t &inputs() const noexcept;
            InputComponent &inputs(const std::string &name) const;
            const output_component_map_t &outputs() const noexcept;
            OutputComponent &outputs(const std::string &name) const;

            void display(std::size_t tick) const noexcept;
            void simulate(std::size_t tick) const;
            void dump() const noexcept;

            nts::ComponentFactory &operator=(const nts::ComponentFactory &rhs) noexcept;
            const std::unique_ptr<nts::IComponent> &operator[](const std::string &key) const;

        private:
            component_map_t m_components;
            input_component_map_t m_input_components;
            output_component_map_t m_output_components;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
