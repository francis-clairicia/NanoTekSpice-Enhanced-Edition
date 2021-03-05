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
            struct Link
            {
                nts::IComponent &component;
                std::size_t pin;
            };

        public:
            Pin() noexcept;
            ~Pin() noexcept;

            nts::Tristate compute(std::size_t tick) const;
            void setLink(nts::IComponent &component, std::size_t pin);
            void dump() const;

            bool hasLinks() const noexcept;

        private:
            std::vector<Link> m_links;
    };
}

#endif /* !PIN_HPP_ */
