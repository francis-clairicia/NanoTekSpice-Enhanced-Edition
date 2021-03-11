/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** types
*/

#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include "IComponent.hpp"

namespace nts
{
    using internComponent_t = std::vector<std::unique_ptr<nts::IComponent>>;
    using componentPin_t = std::vector<std::size_t>;
    using pinMap_t = std::unordered_map<std::size_t, nts::Tristate>;

    enum class ComponentType
    {
        /* Third-party components */
        ThirdParty = -1,
        /* Default components */
        Input,
        Output,
        Clock,
        True,
        False,
        C2716,
        C4001,
        C4008,
        C4011,
        C4013,
        C4017,
        C4030,
        C4040,
        C4069,
        C4071,
        C4081,
        C4094,
        C4512,
        C4514,
        Logger,
        /* Gates */
        GateAND,
        GateNAND,
        GateNOR,
        GateNOT,
        GateOR,
        GateTransmission,
        GateXOR,
        /* Sum */
        Sum,
        /* FlipFlops */
        DTypeFlipFlopWithSR
    };

    const std::unordered_map<ComponentType, std::string> COMPONENT_TYPE_AS_STRING{
        {ComponentType::ThirdParty,          "A third-party"},
        {ComponentType::Input,               "input"},
        {ComponentType::Output,              "output"},
        {ComponentType::Clock,               "clock"},
        {ComponentType::True,                "true"},
        {ComponentType::False,               "false"},
        {ComponentType::C2716,               "2716 'read-only memory'"},
        {ComponentType::C4001,               "4001 'nor'"},
        {ComponentType::C4008,               "4008 'adder'"},
        {ComponentType::C4011,               "4011 'nand'"},
        {ComponentType::C4013,               "4013 'flipflop"},
        {ComponentType::C4017,               "4017 'johnson'"},
        {ComponentType::C4030,               "4030 'xor'"},
        {ComponentType::C4040,               "4040 'counter'"},
        {ComponentType::C4069,               "4069 'invert/not'"},
        {ComponentType::C4071,               "4071 'or'"},
        {ComponentType::C4081,               "4081 'and'"},
        {ComponentType::C4094,               "4094 'shift'"},
        {ComponentType::C4512,               "4512 'selector'"},
        {ComponentType::C4514,               "4514 'decoder'"},
        {ComponentType::GateAND,             "AND"},
        {ComponentType::GateNAND,            "NAND"},
        {ComponentType::GateNOR,             "NOR"},
        {ComponentType::GateNOT,             "NOT"},
        {ComponentType::GateOR,              "OR"},
        {ComponentType::GateTransmission,    "Transmission"},
        {ComponentType::GateXOR,             "XOR"},
        {ComponentType::Sum,                 "SUM"},
        {ComponentType::DTypeFlipFlopWithSR, "D-type Flip Flop with S/R"},
        {ComponentType::Logger,              "logger"},
    };
}

#endif /* !TYPES_HPP_ */
