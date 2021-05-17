/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <map>
#include "InputComponent.hpp"
#include "OutputComponent.hpp"

namespace nts
{
    class Circuit
    {
    public:
        using Components = std::map<std::string, std::unique_ptr<IComponent>>;
        using Inputs = std::map<std::string, InputComponent &>;
        using Outputs = std::map<std::string, OutputComponent &>;

    public:
        Circuit() noexcept = default;
        explicit Circuit(const std::string &filepath);
        Circuit(const Circuit &other) noexcept = delete;
        Circuit(Circuit &&other) noexcept = default;
        ~Circuit() noexcept = default;

        void addComponent(const std::string &type, const std::string &name);
        [[nodiscard]] bool hasComponent(const std::string &name) const noexcept;
        [[nodiscard]] bool empty() const noexcept;

        void setValueForNextTick(const std::string &name, const std::string &value);
        void display(std::size_t tick) const noexcept;
        void simulate(std::size_t tick) const noexcept;
        void dump() const noexcept;

        [[nodiscard]] const InputComponent &input(const std::string &name) const;
        [[nodiscard]] InputComponent &input(const std::string &name);

        [[nodiscard]] const OutputComponent &output(const std::string &name) const;
        [[nodiscard]] OutputComponent &output(const std::string &name);

        Circuit &operator=(const Circuit &rhs) noexcept = delete;
        Circuit &operator=(Circuit &&rhs) noexcept = default;
        const IComponent &operator[](const std::string &key) const;
        IComponent &operator[](const std::string &key);

    private:
        Components m_components;
        Inputs     m_input_components;
        Outputs    m_output_components;
    };
}

#endif /* !CIRCUIT_HPP_ */
