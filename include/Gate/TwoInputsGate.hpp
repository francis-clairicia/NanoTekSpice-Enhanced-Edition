/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** TwoInputsGate
*/

#ifndef TWOINPUTSGATE_HPP_
#define TWOINPUTSGATE_HPP_

#include <string>
#include <list>
#include "IComponent.hpp"
#include "definitions.hpp"

namespace nts
{
    class TwoInputsGate: public IComponent {
        public:
            TwoInputsGate(const std::string &type) noexcept;
            virtual ~TwoInputsGate() override;

            virtual void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            nts::Tristate compute(std::size_t pin) final;
            virtual void dump() const override;
            virtual nts::Tristate operation(nts::Tristate a, nts::Tristate b) const = 0;

        private:
            std::string m_type;
            nts::component_link_t<3> m_links;
            const nts::component_pin_t<2> m_input_pins;
    };
}

#endif /* !TWOINPUTSGATE_HPP_ */
