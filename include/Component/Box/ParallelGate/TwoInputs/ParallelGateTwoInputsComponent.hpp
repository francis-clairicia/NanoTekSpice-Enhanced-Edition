/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ParallelGateTwoInputsComponent
*/

#ifndef PARALLELGATETWOINPUTSCOMPONENT_HPP_
#define PARALLELGATETWOINPUTSCOMPONENT_HPP_

#include <iostream>
#include "BoxComponent.hpp"
#include "GateTwoInputs.hpp"
#include "init_vector_component.hpp"

namespace nts
{
    template<ComponentType Type, typename Gate>
    class ParallelGateTwoInputsComponent final: public BoxComponent
    {
    public:
        static_assert(std::is_base_of_v<GateTwoInputs, Gate>);

    public:
        enum PinName
        {
            INPUT_1A = 1,
            INPUT_1B = 2,
            OUTPUT_1 = 3,
            OUTPUT_2 = 4,
            INPUT_2A = 5,
            INPUT_2B = 6,
            INPUT_3A = 8,
            INPUT_3B = 9,
            OUTPUT_3 = 10,
            OUTPUT_4 = 11,
            INPUT_4A = 12,
            INPUT_4B = 13
        };

    public:
        ParallelGateTwoInputsComponent() noexcept:
            BoxComponent(Type, 14, {
                INPUT_1A,
                INPUT_1B,
                INPUT_2A,
                INPUT_2B,
                INPUT_3A,
                INPUT_3B,
                INPUT_4A,
                INPUT_4B
            }, {
                OUTPUT_1,
                OUTPUT_2,
                OUTPUT_3,
                OUTPUT_4
            }),
            m_components(init_vector_component<Gate>(4))
        {
            setLinkInternal(INPUT_1A, *m_components.at(0), GateTwoInputs::INPUT1);
            setLinkInternal(INPUT_1B, *m_components.at(0), GateTwoInputs::INPUT2);
            setLinkInternal(OUTPUT_1, *m_components.at(0), GateTwoInputs::OUTPUT);

            setLinkInternal(INPUT_2A, *m_components.at(1), GateTwoInputs::INPUT1);
            setLinkInternal(INPUT_2B, *m_components.at(1), GateTwoInputs::INPUT2);
            setLinkInternal(OUTPUT_2, *m_components.at(1), GateTwoInputs::OUTPUT);

            setLinkInternal(INPUT_3A, *m_components.at(2), GateTwoInputs::INPUT1);
            setLinkInternal(INPUT_3B, *m_components.at(2), GateTwoInputs::INPUT2);
            setLinkInternal(OUTPUT_3, *m_components.at(2), GateTwoInputs::OUTPUT);

            setLinkInternal(INPUT_4A, *m_components.at(3), GateTwoInputs::INPUT1);
            setLinkInternal(INPUT_4B, *m_components.at(3), GateTwoInputs::INPUT2);
            setLinkInternal(OUTPUT_4, *m_components.at(3), GateTwoInputs::OUTPUT);
        }

        ~ParallelGateTwoInputsComponent() noexcept override = default;

    private:
        void dumpInternalComponents() const noexcept final
        {
            std::cout << "Internal components:" << '\n';
            for (const auto &component : m_components)
                component->dump();
        }

    private:
        InternComponentList m_components;
    };
}

#endif /* !PARALLELGATETWOINPUTSCOMPONENT_HPP_ */
