/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** SubComponent
*/

#include <iostream>
#include "SubComponent.hpp"
#include "TwoBitsSubComponent.hpp"
#include "init_vector_component.hpp"

namespace nts
{
    SubComponent::SubComponent():
        BoxComponent(ComponentType::Sub, 16, {
            X1, Y1, X2, Y2, X3, Y3, X4, Y4, Bin
        }, {
            S1, S2, S3, S4, Bout
        }),
        m_components(init_vector_component<TwoBitsSubComponent>(4))
    {
        setLinkInternal(X1, *(m_components[0]), TwoBitsSubComponent::Xi);
        setLinkInternal(Y1, *(m_components[0]), TwoBitsSubComponent::Yi);
        setLinkInternal(Bin, *(m_components[0]), TwoBitsSubComponent::Bi);
        setLinkInternal(S1, *(m_components[0]), TwoBitsSubComponent::Diff);

        setLinkInternal(X2, *(m_components[1]), TwoBitsSubComponent::Xi);
        setLinkInternal(Y2, *(m_components[1]), TwoBitsSubComponent::Yi);
        m_components[1]->setLink(TwoBitsSubComponent::Bi, *(m_components[0]), TwoBitsSubComponent::Bo);
        setLinkInternal(S2, *(m_components[1]), TwoBitsSubComponent::Diff);

        setLinkInternal(X3, *(m_components[2]), TwoBitsSubComponent::Xi);
        setLinkInternal(Y3, *(m_components[2]), TwoBitsSubComponent::Yi);
        m_components[2]->setLink(TwoBitsSubComponent::Bi, *(m_components[1]), TwoBitsSubComponent::Bo);
        setLinkInternal(S3, *(m_components[2]), TwoBitsSubComponent::Diff);

        setLinkInternal(X4, *(m_components[3]), TwoBitsSubComponent::Xi);
        setLinkInternal(Y4, *(m_components[3]), TwoBitsSubComponent::Yi);
        m_components[3]->setLink(TwoBitsSubComponent::Bi, *(m_components[2]), TwoBitsSubComponent::Bo);
        setLinkInternal(S4, *(m_components[3]), TwoBitsSubComponent::Diff);
        setLinkInternal(Bout, *(m_components[3]), TwoBitsSubComponent::Bo);
    }

    void SubComponent::dumpInternalComponents() const noexcept
    {
        std::cout << "Internal components:" << '\n';
        for (const auto &component : m_components)
            component->dump();
    }
} // namespace nts


