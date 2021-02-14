/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#ifndef ONEINPUTGATE_HPP_
#define ONEINPUTGATE_HPP_

#include <string>
#include <list>
#include "IComponent.hpp"
#include "definitions.hpp"

namespace nts
{
    class OneInputGate: public nts::IComponent {
        public:
            OneInputGate(const std::string &type) noexcept;
            virtual ~OneInputGate() override;

            virtual void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            nts::Tristate compute(std::size_t pin) final;
            virtual void dump() const override;
            virtual nts::Tristate operation(nts::Tristate a) const = 0;

        private:
            std::string m_type;
            nts::component_link_t<2> m_links;
            const nts::component_pin_t<1> m_input_pins;
    };
}

#endif /* !ONEINPUTGATE_HPP_ */
