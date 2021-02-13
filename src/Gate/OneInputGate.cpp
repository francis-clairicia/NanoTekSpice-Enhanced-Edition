/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** OneInputGate
*/

#include "OneInputGate.hpp"
#include "Exception.hpp"

nts::OneInputGate::OneInputGate(std::size_t input_pin) noexcept:
    m_input_pin(input_pin)
{
}

nts::OneInputGate::~OneInputGate()
{
}

nts::Tristate nts::OneInputGate::compute(const std::string &component_name, nts::component_link_t &links) const
{
    if (m_input_pin == 0 || m_input_pin > links.size())
        throw nts::BadPinException(component_name, m_input_pin);

    auto &link = links.at(m_input_pin - 1);

    return operation((link.first) ? (link.first->compute(link.second)) : nts::UNDEFINED);
}
