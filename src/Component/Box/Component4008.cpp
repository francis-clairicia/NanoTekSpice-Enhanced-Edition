/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4008
*/

#include <iostream>
#include "Component4008.hpp"
#include "SumComponent.hpp"
#include "init_vector_component.hpp"

namespace nts
{
    Component4008::Component4008():
        BoxComponent(ComponentType::C4008, 16, {
            A1, B1, A2, B2, A3, B3, A4, B4, Cin
        }, {
            S1, S2, S3, S4, Cout
        }),
        m_components(init_vector_component<SumComponent>(4))
    {
        setLinkInternal(A1, *(m_components[0]), SumComponent::Ai);
        setLinkInternal(B1, *(m_components[0]), SumComponent::Bi);
        setLinkInternal(Cin, *(m_components[0]), SumComponent::Ci);
        setLinkInternal(S1, *(m_components[0]), SumComponent::Si);

        setLinkInternal(A2, *(m_components[1]), SumComponent::Ai);
        setLinkInternal(B2, *(m_components[1]), SumComponent::Bi);
        m_components[1]->setLink(SumComponent::Ci, *(m_components[0]), SumComponent::Co);
        setLinkInternal(S2, *(m_components[1]), SumComponent::Si);

        setLinkInternal(A3, *(m_components[2]), SumComponent::Ai);
        setLinkInternal(B3, *(m_components[2]), SumComponent::Bi);
        m_components[2]->setLink(SumComponent::Ci, *(m_components[1]), SumComponent::Co);
        setLinkInternal(S3, *(m_components[2]), SumComponent::Si);

        setLinkInternal(A4, *(m_components[3]), SumComponent::Ai);
        setLinkInternal(B4, *(m_components[3]), SumComponent::Bi);
        m_components[3]->setLink(SumComponent::Ci, *(m_components[2]), SumComponent::Co);
        setLinkInternal(S4, *(m_components[3]), SumComponent::Si);
        setLinkInternal(Cout, *(m_components[3]), SumComponent::Co);
    }

    void Component4008::dumpInternalComponents() const noexcept
    {
        std::cout << "Internal components:" << '\n';
        for (const auto &component : m_components)
            component->dump();
    }
} // namespace nts
