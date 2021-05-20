/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** ParallelGateOneInputComponent
*/

#ifndef PARALLELGATEONEINPUTCOMPONENT_HPP_
#define PARALLELGATEONEINPUTCOMPONENT_HPP_

#include <iostream>
#include "BoxComponent.hpp"
#include "init_vector_component.hpp"

namespace nts
{
    template<ComponentType Type, typename Gate>
    class ParallelGateOneInputComponent final: public BoxComponent
    {
    public:
        enum PinName
        {
            INPUT_1  = 1,
            OUTPUT_1 = 2,
            INPUT_2  = 3,
            OUTPUT_2 = 4,
            INPUT_3  = 5,
            OUTPUT_3 = 6,
            OUTPUT_4 = 8,
            INPUT_4  = 9,
            OUTPUT_5 = 10,
            INPUT_5  = 11,
            OUTPUT_6 = 12,
            INPUT_6  = 13
        };

    public:
        ParallelGateOneInputComponent() noexcept:
            BoxComponent(Type, 14, {
                INPUT_1,
                INPUT_2,
                INPUT_3,
                INPUT_4,
                INPUT_5,
                INPUT_6
            }, {
                OUTPUT_1,
                OUTPUT_2,
                OUTPUT_3,
                OUTPUT_4,
                OUTPUT_5,
                OUTPUT_6,
            }),
            m_components(init_vector_component<Gate>(6))
        {
            setLinkInternal(INPUT_1,  *m_components.at(0), Gate::INPUT);
            setLinkInternal(OUTPUT_1, *m_components.at(0), Gate::OUTPUT);

            setLinkInternal(INPUT_2,  *m_components.at(1), Gate::INPUT);
            setLinkInternal(OUTPUT_2, *m_components.at(1), Gate::OUTPUT);

            setLinkInternal(INPUT_3,  *m_components.at(2), Gate::INPUT);
            setLinkInternal(OUTPUT_3, *m_components.at(2), Gate::OUTPUT);

            setLinkInternal(INPUT_4,  *m_components.at(3), Gate::INPUT);
            setLinkInternal(OUTPUT_4, *m_components.at(3), Gate::OUTPUT);

            setLinkInternal(INPUT_5,  *m_components.at(4), Gate::INPUT);
            setLinkInternal(OUTPUT_5, *m_components.at(4), Gate::OUTPUT);

            setLinkInternal(INPUT_6,  *m_components.at(5), Gate::INPUT);
            setLinkInternal(OUTPUT_6, *m_components.at(5), Gate::OUTPUT);
        }
        ~ParallelGateOneInputComponent() noexcept override = default;

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

#endif /* !PARALLELGATEONEINPUTCOMPONENT_HPP_ */
