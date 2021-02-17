/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <map>
#include <memory>
#include "InputComponent.hpp"
#include "OutputComponent.hpp"

namespace nts
{
    class ComponentFactory {
        public:
            using component_creator_t = std::unique_ptr<nts::IComponent> (*)();
            using component_map_t = std::map<std::string, std::unique_ptr<nts::IComponent>>;
            using input_component_map_t = std::map<std::string, std::unique_ptr<nts::InputComponent> &>;
            using output_component_map_t = std::map<std::string, std::unique_ptr<nts::OutputComponent> &>;

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
