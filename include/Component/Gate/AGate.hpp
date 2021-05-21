/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
        virtual Tristate computeOutput() = 0;

    protected:
        const ComponentType m_type;

    private:
        PinList m_pins;
        std::size_t m_output;
    };
}

#endif /* !AGATE_HPP_ */
