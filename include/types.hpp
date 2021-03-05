/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** types
*/

#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <unordered_map>
#include <initializer_list>
#include <string>
#include <vector>
#include <memory>
#include "IComponent.hpp"

namespace nts
{
    using internComponent_t = std::vector<std::unique_ptr<nts::IComponent>>;
    using componentPin_t = std::vector<std::size_t>;
    using pinList_t = std::initializer_list<std::size_t>;
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
        C4512,
        /* Gates */
        GateAND,
        GateNAND,
        GateNOR,
        GateNOT,
        GateOR,
        GateXOR,
        /* Sum */
        Sum,
        /* FlipFlops */
        DTypeFlipFlopWithSR,
        /* Logger */
        Logger
    };

    const std::unordered_map<ComponentType, std::string> COMPONENT_TYPE_AS_STRING{
        {ComponentType::ThirdParty,          "A"},
        {ComponentType::Input,               "input"},
        {ComponentType::Output,              "output"},
        {ComponentType::Clock,               "clock"},
        {ComponentType::True,                "true"},
        {ComponentType::False,               "false"},
        {ComponentType::C4001,               "4001"},
        {ComponentType::C4008,               "4008"},
        {ComponentType::C4011,               "4011"},
        {ComponentType::C4013,               "4013"},
        {ComponentType::C4017,               "4017"},
        {ComponentType::C4030,               "4030"},
        {ComponentType::C4040,               "4040"},
        {ComponentType::C4069,               "4069"},
        {ComponentType::C4071,               "4071"},
        {ComponentType::C4081,               "4081"},
        {ComponentType::C4512,               "4512"},
        {ComponentType::GateAND,             "AND"},
        {ComponentType::GateNAND,            "NAND"},
        {ComponentType::GateNOR,             "NOR"},
        {ComponentType::GateNOT,             "NOT"},
        {ComponentType::GateOR,              "OR"},
        {ComponentType::GateXOR,             "XOR"},
        {ComponentType::Sum,                 "SUM"},
        {ComponentType::DTypeFlipFlopWithSR, "D-type Flip Flop with S/R"},
        {ComponentType::Logger,              "logger"},
    };
}

#endif /* !TYPES_HPP_ */
