/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
        struct Input
        {
            Input(const std::string &_name, InputComponent &_component) noexcept: name{_name}, component{_component} {}
            ~Input() noexcept = default;

            const std::string_view name;
            const InputComponent &component;
        };

        struct Output
        {
            Output(const std::string &_name, OutputComponent &_component) noexcept: name{_name}, component{_component} {}
            ~Output() noexcept = default;

            const std::string_view name;
            const OutputComponent &component;
        };

        using InputsList = std::list<Input>;
        using OutputsList = std::list<Output>;

    public:
        Circuit() noexcept;
        Circuit(const Circuit &other) noexcept = delete;
        Circuit(Circuit &&other) noexcept = default;
        virtual ~Circuit() noexcept = default;

        virtual void addComponent(const std::string &type, const std::string &name);
        [[nodiscard]] bool hasComponent(const std::string &name) const noexcept;
        [[nodiscard]] bool empty() const noexcept;

        [[nodiscard]] std::size_t getTick() const noexcept;

        void simulate() noexcept;
        void dump() const noexcept;

        [[nodiscard]] const InputComponent &input(const std::string &name) const;
        [[nodiscard]] InputComponent &input(const std::string &name);
        [[nodiscard]] InputsList getInputs() const;
        void setValue(const std::string &name, const std::string &value);
        void setValue(const std::string &name, Tristate value);

        [[nodiscard]] const OutputComponent &output(const std::string &name) const;
        [[nodiscard]] OutputComponent &output(const std::string &name);
        [[nodiscard]] OutputsList getOutputs() const;
        Tristate getValue(const std::string &name) const;

        Circuit &operator=(const Circuit &rhs) noexcept = delete;
        Circuit &operator=(Circuit &&rhs) noexcept = default;
        const IComponent &operator[](const std::string &key) const;
        IComponent &operator[](const std::string &key);

    protected:
        using Components = std::map<std::string, IComponent &>;
        using InputsMap = std::map<std::string, InputComponent &>;
        using OutputsMap = std::map<std::string, OutputComponent &>;

    protected:
        Components  m_components;
        InputsMap   m_input_components;
        OutputsMap  m_output_components;

    private:
        using InternComponentMap = std::map<std::string, std::unique_ptr<IComponent>>;

    private:
        InternComponentMap m_component_container;
        std::size_t        m_tick;
    };
}

#endif /* !CIRCUIT_HPP_ */
