/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** TwoInputsGate
*/

#include "TwoInputsGate.hpp"
#include "Exception.hpp"

nts::TwoInputsGate::TwoInputsGate(std::size_t input_pin1, std::size_t input_pin2):
    m_input_pin1(input_pin1), m_input_pin2(input_pin2)
{
    if (m_input_pin1 == m_input_pin2)
        throw GateInputException("The two inputs must not be identical");
}

nts::TwoInputsGate::~TwoInputsGate()
{
}

nts::Tristate nts::TwoInputsGate::compute(const std::string &component_name, nts::component_link_t &links) const
{
    if (m_input_pin1 == 0 || m_input_pin1 > links.size())
        throw nts::BadPinException(component_name, m_input_pin1);
    if (m_input_pin2 == 0 || m_input_pin2 > links.size())
        throw nts::BadPinException(component_name, m_input_pin2);

    auto &link1 = links.at(m_input_pin1 - 1);
    auto &link2 = links.at(m_input_pin2 - 1);

    nts::Tristate input1 = (link1.first) ? (link1.first->compute(link1.second)) : nts::UNDEFINED;
    nts::Tristate input2 = (link2.first) ? (link2.first->compute(link2.second)) : nts::UNDEFINED;

    return operation(input1, input2);
}