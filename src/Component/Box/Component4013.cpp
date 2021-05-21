/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4013
*/

#include <iostream>
#include "Component4013.hpp"
#include "DTypeFlipFlopWithSR.hpp"
#include "init_vector_component.hpp"

namespace nts
{
    Component4013::Component4013():
        BoxComponent(ComponentType::C4013, 14, {
            CLOCK1, RESET1, DATA1, SET1, CLOCK2, RESET2, DATA2, SET2
        }, {
            Q1, Q1n, Q2, Q2n
        }),
        m_components(init_vector_component<DTypeFlipFlopWithSR>(2))
    {
        setLinkInternal(CLOCK1, *m_components.at(0), DTypeFlipFlopWithSR::CLOCK);
        setLinkInternal(RESET1, *m_components.at(0), DTypeFlipFlopWithSR::RESET);
        setLinkInternal(DATA1,  *m_components.at(0), DTypeFlipFlopWithSR::DATA);
        setLinkInternal(SET1,   *m_components.at(0), DTypeFlipFlopWithSR::SET);
        setLinkInternal(Q1,     *m_components.at(0), DTypeFlipFlopWithSR::Q);
        setLinkInternal(Q1n,    *m_components.at(0), DTypeFlipFlopWithSR::Qn);

        setLinkInternal(CLOCK2, *m_components.at(1), DTypeFlipFlopWithSR::CLOCK);
        setLinkInternal(RESET2, *m_components.at(1), DTypeFlipFlopWithSR::RESET);
        setLinkInternal(DATA2,  *m_components.at(1), DTypeFlipFlopWithSR::DATA);
        setLinkInternal(SET2,   *m_components.at(1), DTypeFlipFlopWithSR::SET);
        setLinkInternal(Q2,     *m_components.at(1), DTypeFlipFlopWithSR::Q);
        setLinkInternal(Q2n,    *m_components.at(1), DTypeFlipFlopWithSR::Qn);
    }

    void Component4013::dumpInternalComponents() const noexcept
    {
        std::cout << "Internal components:" << '\n';
        for (const auto &component : m_components)
            component->dump();
    }
} // namespace nts
