/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ComponentType
*/

#ifndef COMPONENTTYPE_HPP_
#define COMPONENTTYPE_HPP_

#include <unordered_map>
#include <string>

namespace nts
{
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
        C4801,
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

    extern const std::unordered_map<ComponentType, std::string> COMPONENT_TYPE_AS_STRING;
} // namespace nts

#endif /* !COMPONENTTYPE_HPP_ */
