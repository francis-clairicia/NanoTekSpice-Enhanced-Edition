/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4063
*/

#ifndef COMPONENT4063_HPP_
#define COMPONENT4063_HPP_

#include "BoxComponent.hpp"
#include "GateTwoInputs.hpp"
#include "GateNOT.hpp"
#include "init_vector_component.hpp"

namespace nts
{
    class Component4063 final: public BoxComponent
    {
    public:
        enum PinName
        {
            B3         = 1,
            A_LT_B_IN  = 2,
            A_EQ_B_IN  = 3,
            A_GT_B_IN  = 4,
            A_GT_B_OUT = 5,
            A_EQ_B_OUT = 6,
            A_LT_B_OUT = 7,
            B0         = 9,
            A0         = 10,
            B1         = 11,
            A1         = 12,
            A2         = 13,
            B2         = 14,
            A3         = 15
        };

    private:
        enum OutputNot
        {
            OUT_NOT_A_LT_B,
            OUT_NOT_A_GT_B,

            NB_OUTPUT_NOT
        };

    public:
        Component4063();
        ~Component4063() noexcept override = default;

    private:
        InternComponentList m_comparator;
        InternComponentList m_out_not;
        InternComponent     m_five_input_and;
        InternComponent     m_true;

    private:
        class Comparator final: public BoxComponent
        {
        public:
            enum PinName
            {
                INPUT_A0      = 1,
                INPUT_A1      = 2,
                INPUT_A2      = 3,
                INPUT_A3      = 4,
                INPUT_B0      = 5,
                INPUT_B1      = 6,
                INPUT_B2      = 7,
                INPUT_B3      = 8,
                INPUT_A_CMP_B = 9,
                OUTPUT_S      = 10
            };

        private:
            enum NotInverter
            {
                NOT_A0,
                NOT_A1,
                NOT_A2,
                NOT_A3,
                NOT_B0,
                NOT_B1,
                NOT_B2,
                NOT_B3,
                NOT_A_CMP_B,

                NB_NOT_COMPONENTS
            };

        public:
            Comparator();
            ~Comparator() noexcept override = default;

        private:
            InternComponentList m_not;
            InternComponentList m_nand;
            InternComponentList m_inv_input_or;
            InternComponentList m_five_input_or;
            InternComponent     m_five_input_nand;
            InternComponent     m_false;
        };

        template<typename Gate>
        class InvertedInputGate final: public BoxComponent
        {
        public:
            static_assert(std::is_base_of_v<GateTwoInputs, Gate>);

        public:
            enum PinName
            {
                INPUT1 = 1,
                INPUT2 = 2,
                OUTPUT = 3,
            };

        public:
            InvertedInputGate():
                BoxComponent{ComponentType::ThirdParty, 3, {INPUT1, INPUT2}, {OUTPUT}},
                m_not1{std::make_unique<GateNOT>()},
                m_not2{std::make_unique<GateNOT>()},
                m_gate{std::make_unique<Gate>()}
            {
                setLinkInternal(INPUT1, *m_not1, GateNOT::INPUT);
                setLinkInternal(INPUT2, *m_not2, GateNOT::INPUT);

                m_gate->setLink(GateTwoInputs::INPUT1, *m_not1, GateNOT::OUTPUT);
                m_gate->setLink(GateTwoInputs::INPUT2, *m_not2, GateNOT::OUTPUT);

                setLinkInternal(OUTPUT, *m_gate, GateTwoInputs::OUTPUT);
            }

            ~InvertedInputGate() noexcept override = default;

        private:
            InternComponent m_not1;
            InternComponent m_not2;
            InternComponent m_gate;
        };

        template<typename Gate>
        class FiveInputGate final: public BoxComponent
        {
        public:
            static_assert(std::is_base_of_v<GateTwoInputs, Gate>);

        public:
            enum PinName
            {
                INPUT1 = 1,
                INPUT2 = 2,
                INPUT3 = 3,
                INPUT4 = 4,
                INPUT5 = 5,
                OUTPUT = 6,
            };

        public:
            FiveInputGate():
                BoxComponent(ComponentType::ThirdParty, 6, {INPUT1, INPUT2, INPUT3, INPUT4, INPUT5}, {OUTPUT}),
                m_gates(init_vector_component<Gate>(4))
            {
                setLinkInternal(INPUT1, *m_gates[0], GateTwoInputs::INPUT1);
                setLinkInternal(INPUT2, *m_gates[0], GateTwoInputs::INPUT2);

                m_gates[1]->setLink(GateTwoInputs::INPUT1, *m_gates[0], GateTwoInputs::OUTPUT);
                setLinkInternal(INPUT3, *m_gates[1], GateTwoInputs::INPUT2);

                m_gates[2]->setLink(GateTwoInputs::INPUT1, *m_gates[1], GateTwoInputs::OUTPUT);
                setLinkInternal(INPUT4, *m_gates[2], GateTwoInputs::INPUT2);

                m_gates[3]->setLink(GateTwoInputs::INPUT1, *m_gates[2], GateTwoInputs::OUTPUT);
                setLinkInternal(INPUT5, *m_gates[3], GateTwoInputs::INPUT2);

                setLinkInternal(OUTPUT, *m_gates[3], GateTwoInputs::OUTPUT);
            }

            ~FiveInputGate() noexcept override = default;

        private:
            InternComponentList m_gates;
        };
    };
} // namespace nts

#endif /* !COMPONENT4063_HPP_ */
