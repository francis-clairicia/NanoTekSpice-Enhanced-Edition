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
                NONE,
                INPUT,
                OUTPUT
            };

        public:
            struct Link
            {
                nts::IComponent &component;
                std::size_t pin;
            };

        public:
            explicit Pin(Pin::Mode mode = Mode::NONE) noexcept;
            Pin(const Pin &other) noexcept = default;
            ~Pin() noexcept = default;

            void setLinkWithExternalComponent(nts::IComponent &component, std::size_t pin) noexcept;
            void setLinkWithInternalComponent(nts::IComponent &component, std::size_t pin) noexcept;
            nts::Tristate compute(std::size_t tick) const;
            void dump() const noexcept;

            Pin &operator=(const Pin &rhs) noexcept = default;
            Pin &operator=(Pin::Mode mode) noexcept;
            bool operator==(Pin::Mode mode) const noexcept;
            bool operator!=(Pin::Mode mode) const noexcept;

        private:
            Pin::Mode              m_mode;
            std::vector<Pin::Link> m_internal_links;
            std::vector<Pin::Link> m_external_links;
    };
}

#endif /* !PIN_HPP_ */
