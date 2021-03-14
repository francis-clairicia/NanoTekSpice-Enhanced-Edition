/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include <vector>
#include "IComponent.hpp"

namespace nts
{
    class Pin {
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
            struct Link
            {
                nts::IComponent &component;
                std::size_t pin;
            };

        public:
            using linkList_t = std::vector<Pin::Link>;

        public:
            Pin() noexcept;
            explicit Pin(Pin::Direction direction, Pin::Mode mode = NONE) noexcept;
            Pin(const Pin &other) noexcept = default;
            ~Pin() noexcept = default;

            void setLinkWithExternalComponent(nts::IComponent &component, std::size_t pin) noexcept;
            void setLinkWithInternalComponent(nts::IComponent &component, std::size_t pin) noexcept;

            nts::Tristate compute(std::size_t tick) const;
            void computeAsInput() noexcept;
            void computeAsOutput() noexcept;

            void dump() const noexcept;

            [[nodiscard]] bool isInput() const noexcept;
            [[nodiscard]] bool isOutput() const noexcept;

            Pin &operator=(const Pin &rhs) noexcept = default;

        private:
            nts::Tristate computeLinks(const Pin::linkList_t &used_links, std::size_t tick) const;

        private:
            int             m_mode;
            Pin::linkList_t m_internal_links;
            Pin::linkList_t m_external_links;
    };
}

#endif /* !PIN_HPP_ */
