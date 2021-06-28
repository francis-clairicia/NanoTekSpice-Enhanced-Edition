/*
** EPITECH PROJECT, 2021
** 1
** File description:
** Component4063
*/

#include <iostream>
#include "Component4063.hpp"
#include "ConstComponent.hpp"
#include "GateAND.hpp"
#include "GateNOT.hpp"
#include "GateNAND.hpp"
#include "GateOR.hpp"


namespace nts
{

    Component4063::Component4063():
        BoxComponent{ComponentType::C4063, 16, {
            A0, A1, A2, A3, B0, B1, B2, B3, A_LT_B_IN, A_EQ_B_IN, A_GT_B_IN
        }, {
            A_LT_B_OUT, A_EQ_B_OUT, A_GT_B_OUT
        }},
        m_comparator{init_vector_component<Comparator>(2)},
        m_out_not{init_vector_component<GateNOT>(NB_OUTPUT_NOT)},
        m_five_input_and{std::make_unique<FiveInputGate<GateAND>>()},
        m_true{std::make_unique<TrueComponent>()}
    {
        using FiveInputGateAND = FiveInputGate<GateAND>;

        setLinkInternal(A0, *m_comparator[0], Comparator::INPUT_A0);
        setLinkInternal(A1, *m_comparator[0], Comparator::INPUT_A1);
        setLinkInternal(A2, *m_comparator[0], Comparator::INPUT_A2);
        setLinkInternal(A3, *m_comparator[0], Comparator::INPUT_A3);
        setLinkInternal(B0, *m_comparator[0], Comparator::INPUT_B0);
        setLinkInternal(B1, *m_comparator[0], Comparator::INPUT_B1);
        setLinkInternal(B2, *m_comparator[0], Comparator::INPUT_B2);
        setLinkInternal(B3, *m_comparator[0], Comparator::INPUT_B3);

        setLinkInternal(B0, *m_comparator[1], Comparator::INPUT_A0);
        setLinkInternal(B1, *m_comparator[1], Comparator::INPUT_A1);
        setLinkInternal(B2, *m_comparator[1], Comparator::INPUT_A2);
        setLinkInternal(B3, *m_comparator[1], Comparator::INPUT_A3);
        setLinkInternal(A0, *m_comparator[1], Comparator::INPUT_B0);
        setLinkInternal(A1, *m_comparator[1], Comparator::INPUT_B1);
        setLinkInternal(A2, *m_comparator[1], Comparator::INPUT_B2);
        setLinkInternal(A3, *m_comparator[1], Comparator::INPUT_B3);

        m_out_not[OUT_NOT_A_LT_B]->setLink(GateNOT::INPUT, *m_comparator[0], Comparator::OUTPUT_S);
        m_out_not[OUT_NOT_A_GT_B]->setLink(GateNOT::INPUT, *m_comparator[1], Comparator::OUTPUT_S);
        setLinkInternal(A_LT_B_OUT, *m_comparator[0], Comparator::OUTPUT_S);
        setLinkInternal(A_GT_B_OUT, *m_comparator[1], Comparator::OUTPUT_S);

        setLinkInternal(A_EQ_B_IN, *m_five_input_and, FiveInputGateAND::INPUT1);
        m_five_input_and->setLink(FiveInputGateAND::INPUT2, *m_out_not[OUT_NOT_A_LT_B], GateNOT::OUTPUT);
        m_five_input_and->setLink(FiveInputGateAND::INPUT3, *m_out_not[OUT_NOT_A_GT_B], GateNOT::OUTPUT);
        m_five_input_and->setLink(FiveInputGateAND::INPUT4, *m_true, TrueComponent::OUTPUT);
        m_five_input_and->setLink(FiveInputGateAND::INPUT5, *m_true, TrueComponent::OUTPUT);

        setLinkInternal(A_EQ_B_OUT, *m_five_input_and, FiveInputGateAND::OUTPUT);
    }

    Component4063::Comparator::Comparator():
        BoxComponent{ComponentType::ThirdParty, 10, {
            INPUT_A0, INPUT_A1, INPUT_A2, INPUT_A3,
            INPUT_B0, INPUT_B1, INPUT_B2, INPUT_B3,
            INPUT_A_CMP_B
        }, {
            OUTPUT_S
        }},
        m_not{init_vector_component<GateNOT>(NB_NOT_COMPONENTS)},
        m_nand{init_vector_component<GateNAND>(8)},
        m_inv_input_or{init_vector_component<InvertedInputGate<GateOR>>(4)},
        m_five_input_or{init_vector_component<FiveInputGate<GateOR>>(4)},
        m_false{std::make_unique<FalseComponent>()}
    {
        using InvertedInputGateOR = InvertedInputGate<GateOR>;
        using FiveInputGateOR = FiveInputGate<GateOR>;
        using FiveInputGateAND = FiveInputGate<GateAND>;

        setLinkInternal(INPUT_A0, *m_not[NOT_A0], GateNOT::INPUT);
        setLinkInternal(INPUT_A1, *m_not[NOT_A1], GateNOT::INPUT);
        setLinkInternal(INPUT_A2, *m_not[NOT_A2], GateNOT::INPUT);
        setLinkInternal(INPUT_A3, *m_not[NOT_A3], GateNOT::INPUT);
        setLinkInternal(INPUT_B0, *m_not[NOT_B0], GateNOT::INPUT);
        setLinkInternal(INPUT_B1, *m_not[NOT_B1], GateNOT::INPUT);
        setLinkInternal(INPUT_B2, *m_not[NOT_B2], GateNOT::INPUT);
        setLinkInternal(INPUT_B3, *m_not[NOT_B3], GateNOT::INPUT);
        setLinkInternal(INPUT_A_CMP_B, *m_not[NOT_A_CMP_B], GateNOT::INPUT);

        m_nand[0]->setLink(GateNAND::INPUT1, *m_not[NOT_A3], GateNOT::OUTPUT);
        setLinkInternal(B3, *m_nand[0], GateNAND::INPUT2);

        setLinkInternal(A3, *m_nand[1], GateNAND::INPUT1);
        m_nand[1]->setLink(GateNAND::INPUT2, *m_not[NOT_B3], GateNOT::OUTPUT);

        m_nand[2]->setLink(GateNAND::INPUT1, *m_not[NOT_A2], GateNOT::OUTPUT);
        setLinkInternal(B2, *m_nand[2], GateNAND::INPUT2);

        setLinkInternal(A2, *m_nand[3], GateNAND::INPUT1);
        m_nand[3]->setLink(GateNAND::INPUT2, *m_not[NOT_B2], GateNOT::OUTPUT);

        m_nand[4]->setLink(GateNAND::INPUT1, *m_not[NOT_A1], GateNOT::OUTPUT);
        setLinkInternal(B1, *m_nand[4], GateNAND::INPUT2);

        setLinkInternal(A1, *m_nand[5], GateNAND::INPUT1);
        m_nand[5]->setLink(GateNAND::INPUT2, *m_not[NOT_B1], GateNOT::OUTPUT);

        m_nand[6]->setLink(GateNAND::INPUT1, *m_not[NOT_A0], GateNOT::OUTPUT);
        setLinkInternal(B0, *m_nand[6], GateNAND::INPUT2);

        setLinkInternal(A0, *m_nand[7], GateNAND::INPUT1);
        m_nand[7]->setLink(GateNAND::INPUT2, *m_not[NOT_B0], GateNOT::OUTPUT);

        m_inv_input_or[0]->setLink(InvertedInputGateOR::INPUT1, *m_nand[0], GateNAND::OUTPUT);
        m_inv_input_or[0]->setLink(InvertedInputGateOR::INPUT2, *m_nand[1], GateNAND::OUTPUT);

        m_inv_input_or[1]->setLink(InvertedInputGateOR::INPUT1, *m_nand[2], GateNAND::OUTPUT);
        m_inv_input_or[1]->setLink(InvertedInputGateOR::INPUT2, *m_nand[3], GateNAND::OUTPUT);

        m_inv_input_or[2]->setLink(InvertedInputGateOR::INPUT1, *m_nand[4], GateNAND::OUTPUT);
        m_inv_input_or[2]->setLink(InvertedInputGateOR::INPUT2, *m_nand[5], GateNAND::OUTPUT);

        m_inv_input_or[3]->setLink(InvertedInputGateOR::INPUT1, *m_nand[6], GateNAND::OUTPUT);
        m_inv_input_or[3]->setLink(InvertedInputGateOR::INPUT2, *m_nand[7], GateNAND::OUTPUT);

        m_five_input_or[0]->setLink(FiveInputGateOR::INPUT1, *m_inv_input_or[0], InvertedInputGateOR::OUTPUT);
        m_five_input_or[0]->setLink(FiveInputGateOR::INPUT2, *m_nand[2], GateNAND::OUTPUT);
        m_five_input_or[0]->setLink(FiveInputGateOR::INPUT3, *m_false, FalseComponent::OUTPUT);
        m_five_input_or[0]->setLink(FiveInputGateOR::INPUT4, *m_false, FalseComponent::OUTPUT);
        m_five_input_or[0]->setLink(FiveInputGateOR::INPUT5, *m_false, FalseComponent::OUTPUT);

        m_five_input_or[1]->setLink(FiveInputGateOR::INPUT1, *m_inv_input_or[0], InvertedInputGateOR::OUTPUT);
        m_five_input_or[1]->setLink(FiveInputGateOR::INPUT2, *m_inv_input_or[1], InvertedInputGateOR::OUTPUT);
        m_five_input_or[1]->setLink(FiveInputGateOR::INPUT3, *m_nand[4], GateNAND::OUTPUT);
        m_five_input_or[1]->setLink(FiveInputGateOR::INPUT4, *m_false, FalseComponent::OUTPUT);
        m_five_input_or[1]->setLink(FiveInputGateOR::INPUT5, *m_false, FalseComponent::OUTPUT);

        m_five_input_or[2]->setLink(FiveInputGateOR::INPUT1, *m_inv_input_or[0], InvertedInputGateOR::OUTPUT);
        m_five_input_or[2]->setLink(FiveInputGateOR::INPUT2, *m_inv_input_or[1], InvertedInputGateOR::OUTPUT);
        m_five_input_or[2]->setLink(FiveInputGateOR::INPUT3, *m_inv_input_or[2], InvertedInputGateOR::OUTPUT);
        m_five_input_or[2]->setLink(FiveInputGateOR::INPUT4, *m_nand[6], GateNAND::OUTPUT);
        m_five_input_or[2]->setLink(FiveInputGateOR::INPUT5, *m_false, FalseComponent::OUTPUT);

        m_five_input_or[3]->setLink(FiveInputGateOR::INPUT1, *m_inv_input_or[0], InvertedInputGateOR::OUTPUT);
        m_five_input_or[3]->setLink(FiveInputGateOR::INPUT2, *m_inv_input_or[1], InvertedInputGateOR::OUTPUT);
        m_five_input_or[3]->setLink(FiveInputGateOR::INPUT3, *m_inv_input_or[2], InvertedInputGateOR::OUTPUT);
        m_five_input_or[3]->setLink(FiveInputGateOR::INPUT4, *m_inv_input_or[3], InvertedInputGateOR::OUTPUT);
        m_five_input_or[3]->setLink(FiveInputGateOR::INPUT5, *m_not[NOT_A_CMP_B], GateNOT::OUTPUT);

        m_five_input_nand->setLink(FiveInputGateAND::INPUT1, *m_nand[0], GateNAND::OUTPUT);
        m_five_input_nand->setLink(FiveInputGateAND::INPUT2, *m_five_input_or[0], FiveInputGateOR::OUTPUT);
        m_five_input_nand->setLink(FiveInputGateAND::INPUT3, *m_five_input_or[1], FiveInputGateOR::OUTPUT);
        m_five_input_nand->setLink(FiveInputGateAND::INPUT4, *m_five_input_or[2], FiveInputGateOR::OUTPUT);
        m_five_input_nand->setLink(FiveInputGateAND::INPUT5, *m_five_input_or[3], FiveInputGateOR::OUTPUT);
    }

} // namespace nts
