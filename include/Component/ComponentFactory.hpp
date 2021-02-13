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
            ComponentFactory() noexcept;
            ComponentFactory(const nts::ComponentFactory &other) noexcept;
            ~ComponentFactory() noexcept;

            std::unique_ptr<nts::IComponent> createComponent(const std::string &type) const;

            component_map_t &get() noexcept;
            input_component_map_t &inputs() noexcept;
            output_component_map_t &outputs() noexcept;

            void dump() const noexcept;

            nts::ComponentFactory &operator=(const nts::ComponentFactory &rhs) noexcept;

        private:
            std::unordered_map<std::string, component_creator_t> m_component_creator;
            component_map_t m_components;
            input_component_map_t m_input_components;
            output_component_map_t m_output_components;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
