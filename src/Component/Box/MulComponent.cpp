/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** MulComponent
*/

#include "MulComponent.hpp"
#include "Component4008.hpp"
#include "GateAND.hpp"
#include "ConstComponent.hpp"
#include "init_vector_component.hpp"

namespace nts
{
    MulComponent::MulComponent():
        BoxComponent{ComponentType::Mul, 18, {
            A0, A1, A2, A3, B0, B1, B2, B3
        }, {
            S0, S1, S2, S3, S4, S5, S6, S7
        }},
        m_adder{init_vector_component<Component4008>(3)},
        m_and{init_vector_component<GateAND>(16)},
        m_zero{std::make_unique<FalseComponent>()}
    {
        setLinkInternal(A0, *m_and[0], GateAND::INPUT1);
        setLinkInternal(B0, *m_and[0], GateAND::INPUT2);

        setLinkInternal(A1, *m_and[1], GateAND::INPUT1);
        setLinkInternal(B0, *m_and[1], GateAND::INPUT2);

        setLinkInternal(A2, *m_and[2], GateAND::INPUT1);
        setLinkInternal(B0, *m_and[2], GateAND::INPUT2);

        setLinkInternal(A3, *m_and[3], GateAND::INPUT1);
        setLinkInternal(B0, *m_and[3], GateAND::INPUT2);

        m_adder[0]->setLink(Component4008::B1, *m_and[1], GateAND::OUTPUT);
        m_adder[0]->setLink(Component4008::B2, *m_and[2], GateAND::OUTPUT);
        m_adder[0]->setLink(Component4008::B3, *m_and[3], GateAND::OUTPUT);
        m_adder[0]->setLink(Component4008::B4, *m_zero, FalseComponent::OUTPUT);

        setLinkInternal(A0, *m_and[4], GateAND::INPUT1);
        setLinkInternal(B1, *m_and[4], GateAND::INPUT2);

        setLinkInternal(A1, *m_and[5], GateAND::INPUT1);
        setLinkInternal(B1, *m_and[5], GateAND::INPUT2);

        setLinkInternal(A2, *m_and[6], GateAND::INPUT1);
        setLinkInternal(B1, *m_and[6], GateAND::INPUT2);

        setLinkInternal(A3, *m_and[7], GateAND::INPUT1);
        setLinkInternal(B1, *m_and[7], GateAND::INPUT2);

        m_adder[0]->setLink(Component4008::A1, *m_and[4], GateAND::OUTPUT);
        m_adder[0]->setLink(Component4008::A2, *m_and[5], GateAND::OUTPUT);
        m_adder[0]->setLink(Component4008::A3, *m_and[6], GateAND::OUTPUT);
        m_adder[0]->setLink(Component4008::A4, *m_and[7], GateAND::OUTPUT);

        setLinkInternal(A0, *m_and[8], GateAND::INPUT1);
        setLinkInternal(B2, *m_and[8], GateAND::INPUT2);

        setLinkInternal(A1, *m_and[9], GateAND::INPUT1);
        setLinkInternal(B2, *m_and[9], GateAND::INPUT2);

        setLinkInternal(A2, *m_and[10], GateAND::INPUT1);
        setLinkInternal(B2, *m_and[10], GateAND::INPUT2);

        setLinkInternal(A3, *m_and[11], GateAND::INPUT1);
        setLinkInternal(B2, *m_and[11], GateAND::INPUT2);

        m_adder[1]->setLink(Component4008::A1, *m_and[8], GateAND::OUTPUT);
        m_adder[1]->setLink(Component4008::A2, *m_and[9], GateAND::OUTPUT);
        m_adder[1]->setLink(Component4008::A3, *m_and[10], GateAND::OUTPUT);
        m_adder[1]->setLink(Component4008::A4, *m_and[11], GateAND::OUTPUT);
        m_adder[1]->setLink(Component4008::B1, *m_adder[0], Component4008::S2);
        m_adder[1]->setLink(Component4008::B2, *m_adder[0], Component4008::S3);
        m_adder[1]->setLink(Component4008::B3, *m_adder[0], Component4008::S4);
        m_adder[1]->setLink(Component4008::B4, *m_adder[0], Component4008::Cout);

        setLinkInternal(A0, *m_and[12], GateAND::INPUT1);
        setLinkInternal(B3, *m_and[12], GateAND::INPUT2);

        setLinkInternal(A1, *m_and[13], GateAND::INPUT1);
        setLinkInternal(B3, *m_and[13], GateAND::INPUT2);

        setLinkInternal(A2, *m_and[14], GateAND::INPUT1);
        setLinkInternal(B3, *m_and[14], GateAND::INPUT2);

        setLinkInternal(A3, *m_and[15], GateAND::INPUT1);
        setLinkInternal(B3, *m_and[15], GateAND::INPUT2);

        m_adder[2]->setLink(Component4008::A1, *m_and[12], GateAND::OUTPUT);
        m_adder[2]->setLink(Component4008::A2, *m_and[13], GateAND::OUTPUT);
        m_adder[2]->setLink(Component4008::A3, *m_and[14], GateAND::OUTPUT);
        m_adder[2]->setLink(Component4008::A4, *m_and[15], GateAND::OUTPUT);
        m_adder[2]->setLink(Component4008::B1, *m_adder[1], Component4008::S2);
        m_adder[2]->setLink(Component4008::B2, *m_adder[1], Component4008::S3);
        m_adder[2]->setLink(Component4008::B3, *m_adder[1], Component4008::S4);
        m_adder[2]->setLink(Component4008::B4, *m_adder[1], Component4008::Cout);

        setLinkInternal(S0, *m_and[0], GateAND::OUTPUT);
        setLinkInternal(S1, *m_adder[0], Component4008::S1);
        setLinkInternal(S2, *m_adder[1], Component4008::S1);
        setLinkInternal(S3, *m_adder[2], Component4008::S1);
        setLinkInternal(S4, *m_adder[2], Component4008::S2);
        setLinkInternal(S5, *m_adder[2], Component4008::S3);
        setLinkInternal(S6, *m_adder[2], Component4008::S4);
        setLinkInternal(S7, *m_adder[2], Component4008::Cout);
    }
} // namespace nts
