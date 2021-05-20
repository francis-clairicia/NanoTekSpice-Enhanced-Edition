/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include <list>
#include "IComponent.hpp"

namespace nts
{
    class Pin
    {
    public:
        enum Direction
        {
            UNIDIRECTIONAL = 0,
            BIDIRECTIONAL  = 1
        };

        enum Mode
        {
            NONE   = 0,
            INPUT  = 1 << 1,
            OUTPUT = 1 << 2
        };

    public:
        Pin() noexcept;
        explicit Pin(Pin::Direction direction, Pin::Mode mode = NONE) noexcept;
        Pin(const Pin &other) noexcept = default;
        Pin(Pin &&other) noexcept = default;
        ~Pin() noexcept = default;

        void setLinkWithExternalComponent(IComponent &component, std::size_t pin) noexcept;
        void setLinkWithInternalComponent(IComponent &component, std::size_t pin) noexcept;

        [[nodiscard]] bool hasInternalLinks() const noexcept;

        Tristate computeInternalLinks(std::size_t tick) const;
        Tristate computeExternalLinks(std::size_t tick) const;
        void computeAsInput() noexcept;
        void computeAsOutput() noexcept;

        void dump() const noexcept;

        [[nodiscard]] bool isInput() const noexcept;
        [[nodiscard]] bool isOutput() const noexcept;
        [[nodiscard]] bool isBidirectional() const noexcept;

        Pin &operator=(const Pin &rhs) noexcept = default;
        Pin &operator=(Pin &&rhs) noexcept = default;

    private:
        struct Link
        {
            Link(IComponent &_component, std::size_t _pin) noexcept: component{_component}, pin{_pin} {}
            ~Link() noexcept = default;

            IComponent &component;
            std::size_t pin;
        };

    private:
        using Links = std::list<Pin::Link>;

    private:
        Tristate computeLinks(const Links &used_links, std::size_t tick) const;

    private:
        int   m_mode;
        Links m_internal_links;
        Links m_external_links;
    };
}

#endif /* !PIN_HPP_ */
