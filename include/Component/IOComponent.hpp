/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** IOComponent
*/

#ifndef IOCOMPONENT_HPP_
#define IOCOMPONENT_HPP_

#include <string>
#include <unordered_map>
#include "IComponent.hpp"

namespace nts
{
    class IOComponent: public nts::IComponent {
        public:
            static const std::unordered_map<std::string, nts::Tristate> TRISTATE_CONVERTER;

        public:
            IOComponent(const std::string &type) noexcept;

            void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const override;

            std::string getValueAsString() const noexcept;

        protected:
            IComponent *m_link;
            std::size_t m_link_pin;
            std::string m_type;
            nts::Tristate m_value;
    };
}

#endif /* !IOCOMPONENT_HPP_ */
