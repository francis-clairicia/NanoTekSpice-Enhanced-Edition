/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** nts::IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <cstddef>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
    public:
        virtual ~IComponent() noexcept = default;

        virtual void simulate(std::size_t tick) = 0;
        virtual Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
        virtual void dump() const noexcept = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
