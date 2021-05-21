/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentType
*/

#include "ComponentType.hpp"

namespace nts
{
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
        {ComponentType::C4801,               "4801 'random-access memory'"},
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
} // namespace nts

