/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <map>
#include "ComponentFactory.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"

namespace nts
{
    class Circuit {
        public:
            using componentMap_t = std::map<std::string, std::unique_ptr<nts::IComponent>>;
            using inputComponentMap_t = std::map<std::string, nts::InputComponent &>;
            using outputComponentMap_t = std::map<std::string, nts::OutputComponent &>;

        public:
            Circuit() noexcept;
            Circuit(const std::string &filepath);
            Circuit(const nts::Circuit &other) noexcept = delete;
            Circuit(nts::Circuit &&other) noexcept = delete;
            ~Circuit() noexcept;

            void addComponent(const std::string &type, const std::string &name);
            [[nodiscard]] bool hasComponent(const std::string &name) const noexcept;
            [[nodiscard]] bool empty() const noexcept;

            void setValueForNextTick(const std::string &name, const std::string &value);
            void display(std::size_t tick) const noexcept;
            void simulate(std::size_t tick) const noexcept;
            void dump() const noexcept;

            nts::Circuit &operator=(const nts::Circuit &rhs) noexcept = delete;
            nts::IComponent &operator[](const std::string &key) const;

        private:
            ComponentFactory     m_factory;
            componentMap_t       m_components;
            inputComponentMap_t  m_input_components;
            outputComponentMap_t m_output_components;
    };
}

#endif /* !CIRCUIT_HPP_ */
