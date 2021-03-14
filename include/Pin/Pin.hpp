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
            enum Mode
            {
                NONE   = 0,
                INPUT  = 1 << 0,
                OUTPUT = 1 << 1,
                BOTH   = INPUT | OUTPUT
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
            explicit Pin(Pin::Mode mode = Mode::NONE) noexcept;
            Pin(const Pin &other) noexcept = default;
            ~Pin() noexcept = default;

            void setLinkWithExternalComponent(nts::IComponent &component, std::size_t pin) noexcept;
            void setLinkWithInternalComponent(nts::IComponent &component, std::size_t pin) noexcept;

            nts::Tristate compute(std::size_t tick) const;
            nts::Tristate computeAsInput(std::size_t tick) const;
            nts::Tristate computeAsOutput(std::size_t tick) const;

            void dump() const noexcept;

            Pin &operator=(const Pin &rhs) noexcept = default;
            Pin &operator=(Pin::Mode mode) noexcept;
            bool operator==(Pin::Mode mode) const noexcept;
            bool operator!=(Pin::Mode mode) const noexcept;

        private:
            nts::Tristate computeLinks(const Pin::linkList_t &used_links, std::size_t tick) const;

        private:
            Pin::Mode       m_mode;
            Pin::linkList_t m_internal_links;
            Pin::linkList_t m_external_links;
    };
}

#endif /* !PIN_HPP_ */
