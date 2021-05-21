/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** SinglePinComponent
*/

#ifndef SINGLEPINCOMPONENT_HPP_
#define SINGLEPINCOMPONENT_HPP_

#include "types.hpp"
#include "Pin.hpp"

namespace nts
{
    class SinglePinComponent: public IComponent
    {
    public:
        SinglePinComponent(ComponentType type, Pin::Mode pin_mode) noexcept;
        SinglePinComponent(const SinglePinComponent &other) noexcept = delete;
        SinglePinComponent(SinglePinComponent &&other) noexcept = default;
        ~SinglePinComponent() noexcept override = default;

        Tristate compute(std::size_t pin) final;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) final;
        void dump() const noexcept final;

        [[nodiscard]] Tristate getValue() const noexcept;

        SinglePinComponent &operator=(const SinglePinComponent &rhs) noexcept = delete;
        SinglePinComponent &operator=(SinglePinComponent &&rhs) noexcept = default;

    protected:
        virtual Tristate computeOutput();

    protected:
        Pin                 m_pin;
        const ComponentType m_type;
        Tristate            m_value;
    };
}

#endif /* !SINGLEPINCOMPONENT_HPP_ */
