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
    struct Link
    {
        IComponent *component;
        std::size_t pin;
    };

    using internComponent_t = std::vector<std::unique_ptr<IComponent>>;
    using componentPin_t = std::vector<std::size_t>;
    using pinList_t = std::initializer_list<std::size_t>;

    enum ComponentType
    {
        /* Third-party components */
        ThirdPartyComponentType = -1,
        /* Default components */
        InputComponentType,
        OutputComponentType,
        ClockComponentType,
        TrueComponentType,
        FalseComponentType,
        Component4001Type,
        Component4008Type,
        Component4011Type,
        Component4013Type,
        Component4017Type,
        Component4030Type,
        Component4069Type,
        Component4071Type,
        Component4081Type,
        /* Gates */
        GateANDType,
        GateNANDType,
        GateNORType,
        GateNOTType,
        GateORType,
        GateXORType,
        BufferGateType,
        /* Sum */
        SumComponentType,
        /* FlipFlops */
        DTypeFlipFlopWithSRType
    };

    const std::unordered_map<ComponentType, std::string> COMPONENT_TYPE_AS_STRING{
        {ThirdPartyComponentType, "A"},
        {InputComponentType,      "input"},
        {OutputComponentType,     "output"},
        {ClockComponentType,      "clock"},
        {TrueComponentType,       "true"},
        {FalseComponentType,      "false"},
        {Component4001Type,       "4001"},
        {Component4008Type,       "4008"},
        {Component4011Type,       "4011"},
        {Component4013Type,       "4013"},
        {Component4017Type,       "4017"},
        {Component4030Type,       "4030"},
        {Component4069Type,       "4069"},
        {Component4071Type,       "4071"},
        {Component4081Type,       "4081"},
        {GateANDType,             "AND"},
        {GateNANDType,            "NAND"},
        {GateNORType,             "NOR"},
        {GateNOTType,             "NOT"},
        {GateORType,              "OR"},
        {GateXORType,             "XOR"},
        {BufferGateType,          "Buffer"},
        {SumComponentType,        "SUM"},
        {DTypeFlipFlopWithSRType, "D-type Flip Flop with S/R"},
    };
}

#endif /* !TYPES_HPP_ */
