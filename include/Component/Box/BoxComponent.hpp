/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** BoxComponent
*/

#ifndef BOXCOMPONENT_HPP_
#define BOXCOMPONENT_HPP_

#include "PinList.hpp"

namespace nts
{
    class BoxComponent: public IComponent
    {
    public:
        BoxComponent(ComponentType type, std::size_t nb_pins, PinList::Initializer input_pins, PinList::Initializer output_pins) noexcept;
        BoxComponent(const BoxComponent &other) noexcept = delete;
        BoxComponent(BoxComponent &&other) noexcept = default;
        ~BoxComponent() noexcept override = default;

        void simulate(std::size_t tick) final;
        Tristate compute(std::size_t pin) final;
        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) final;
        void dump() const noexcept final;

        BoxComponent &operator=(const BoxComponent &rhs) noexcept = delete;
        BoxComponent &operator=(BoxComponent &&rhs) noexcept = default;

    protected:
        void setLinkInternal(std::size_t pin, IComponent &other, std::size_t otherPin);
        virtual void dumpInternalComponents() const noexcept;

    protected:
        const ComponentType m_type;

    private:
        PinList     m_pins;
    };
}

#endif /* !BOXCOMPONENT_HPP_ */
