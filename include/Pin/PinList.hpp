/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** PinList
*/

#ifndef PINLIST_HPP_
#define PINLIST_HPP_

#include <initializer_list>
#include <type_traits>
#include <functional>
#include "types.hpp"
#include "Pin.hpp"

namespace nts
{
    class PinList
    {
    public:
        using Initializer = std::initializer_list<std::size_t>;

    private:
        class Locker
        {
        public:
            Locker(PinList &pin_list) noexcept;
            ~Locker() noexcept;

        private:
            PinList &m_pin_list;
        };

    public:
        PinList(ComponentType owner, std::size_t nb, Initializer inputs, Initializer outputs, bool accept_io = false);
        ~PinList() noexcept = default;

        [[nodiscard]] const ComponentPins &getInputPins() const noexcept;
        [[nodiscard]] const ComponentPins &getOutputPins() const noexcept;
        [[nodiscard]] bool hasPin(std::size_t pin) const noexcept;

        const Tristate &input(std::size_t pin) const;
        Tristate &input(std::size_t pin);

        const Tristate &output(std::size_t pin) const;
        Tristate &output(std::size_t pin);

        inline void simulate(std::size_t tick) { updateInputs(tick); }

        template<typename Integer, typename Callable, typename... Args>
        void simulate(Integer tick, Callable &&func, Args &&...args)
        {
            using IntegerNoRef = std::remove_reference_t<Integer>;
            static_assert(std::is_integral_v<IntegerNoRef>, "Type of tick is not an integer.");
            static_assert(std::is_invocable_v<Callable, Args...>, "func is not invocable.");

            if constexpr(std::is_integral_v<IntegerNoRef> && std::is_invocable_v<Callable, Args...>) {
                if (updateInputs(tick)) {
                    std::invoke(std::forward<Callable>(func), std::forward<Args>(args)...);
                }
            }
        }

        Tristate compute(std::size_t pin);
        Tristate computeInternal(IComponent &component, std::size_t pin);

        void setAllOutputs(Tristate v) noexcept;

        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
        void setLinkInternal(std::size_t pin, IComponent &other, std::size_t otherPin);

        void dump() const noexcept;

    private:
        using PinMap = std::unordered_map<std::size_t, Pin>;
        using PinValues = std::unordered_map<std::size_t, Tristate>;

    private:
        bool updateInputs(std::size_t tick);
        void checkPin(std::size_t pin) const;
        void checkPin(const std::vector<std::size_t> &list, std::size_t pin) const;

        void lock() noexcept;
        void unlock() noexcept;

    private:
        const ComponentType m_owner;
        const ComponentPins m_input_pins;
        const ComponentPins m_output_pins;
        const ComponentPins m_both_input_and_output_pins;
        std::size_t         m_actual_tick;
        bool                m_locked;
        PinMap              m_pins;
        PinValues           m_input_values;
        PinValues           m_output_values;
    };
}

#endif /* !PINLIST_HPP_ */
