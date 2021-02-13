/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "IComponent.hpp"
#include "definitions.hpp"

namespace nts
{
    class InputComponent: public IComponent {
        public:
            InputComponent() noexcept;
            virtual ~InputComponent() override;

            virtual void simulate(std::size_t tick) override;
            nts::Tristate compute(std::size_t pin) final;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
            virtual void dump() const override;

            const std::string getValueAsString() const noexcept;
            void setValue(const std::string &value);

            const std::string &getName() const noexcept;
            void setName(const std::string &name) noexcept;

        protected:
            std::string m_name;
            nts::Tristate m_value;
    };  
}


#endif /* !INPUTCOMPONENT_HPP_ */
