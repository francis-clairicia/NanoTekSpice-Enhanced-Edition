/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_

#include "InputComponent.hpp"

namespace nts
{
    class ClockComponent final: public InputComponent
    {
    public:
        ClockComponent() noexcept;
        ~ClockComponent() noexcept override = default;

        void simulate(std::size_t tick) final;
        void setValue(Tristate value) noexcept final;

    private:
        bool m_invert_value;
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
