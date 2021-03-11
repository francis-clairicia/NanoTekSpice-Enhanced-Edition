/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** SinglePinComponent
*/

#ifndef SINGLEPINCOMPONENT_HPP_
#define SINGLEPINCOMPONENT_HPP_

#include "types.hpp"
#include "Pin.hpp"

namespace nts
{
    class SinglePinComponent: public nts::IComponent {
        public:
            SinglePinComponent(nts::ComponentType type, nts::Pin::Mode pin_mode) noexcept;
            ~SinglePinComponent() noexcept = default;

            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            void dump() const noexcept final;

            [[nodiscard]] nts::Tristate getValue() const noexcept;

        protected:
            virtual nts::Tristate computeOutput();

        protected:
            nts::Pin                 m_pin;
            const nts::ComponentType m_type;
            nts::Tristate            m_value;
    };
}

#endif /* !SINGLEPINCOMPONENT_HPP_ */
