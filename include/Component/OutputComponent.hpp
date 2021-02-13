/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include "IComponent.hpp"
#include "definitions.hpp"

namespace nts
{
    class OutputComponent: public IComponent {
        public:
            OutputComponent() noexcept;
            virtual ~OutputComponent() override;

            virtual void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            virtual void dump() const override;

            const std::string getValueAsString() const noexcept;

        protected:
            IComponent *m_link;
            std::size_t m_link_pin;
            std::string m_type;
            nts::Tristate m_value;
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
