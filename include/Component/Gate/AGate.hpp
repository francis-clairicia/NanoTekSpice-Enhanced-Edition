/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** AGate
*/

#ifndef AGATE_HPP_
#define AGATE_HPP_

#include "PinList.hpp"

namespace nts
{
    class AGate: public IComponent
    {
    public:
        AGate(ComponentType type, std::size_t nb_pins, PinList::Initializer input_pins, std::size_t output_pin) noexcept;
        AGate(const AGate &other) noexcept = delete;
        AGate(AGate &&other) noexcept = default;
        ~AGate() noexcept override = default;

        void simulate(std::size_t tick) final;
        Tristate compute(std::size_t pin) final;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) final;
        void dump() const noexcept final;

        AGate &operator=(const AGate &rhs) noexcept = delete;
        AGate &operator=(AGate &&rhs) noexcept = default;

    protected:
        virtual Tristate computeOutput(std::size_t tick) = 0;

    protected:
        Tristate             m_value;
        const ComponentType  m_type;
        PinList              m_pins;

    private:
        std::size_t               m_actual_tick;
    };
}

#endif /* !AGATE_HPP_ */
