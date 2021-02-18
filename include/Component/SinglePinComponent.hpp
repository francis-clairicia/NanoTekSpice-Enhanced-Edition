/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SinglePinComponent
*/

#ifndef SINGLEPINCOMPONENT_HPP_
#define SINGLEPINCOMPONENT_HPP_

#include <string>
#include <unordered_map>
#include "IComponent.hpp"

namespace nts
{
    class SinglePinComponent: public nts::IComponent {
        public:
            SinglePinComponent(const std::string &type) noexcept;

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const override;

            const std::string &getValueAsString() const noexcept;

        protected:
            IComponent *m_link;
            std::size_t m_link_pin;
            std::string m_type;
            nts::Tristate m_value;
    };
}

#endif /* !SINGLEPINCOMPONENT_HPP_ */
