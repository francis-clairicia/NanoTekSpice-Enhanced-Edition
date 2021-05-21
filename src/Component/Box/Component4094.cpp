/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** Component4094
*/

#include "Component4094.hpp"
#include "ConstComponent.hpp"
#include "DTypeFlipFlopWithSR.hpp"
#include "GateNOT.hpp"
#include "GateTransmission.hpp"
#include "init_vector_component.hpp"

namespace nts
{
    using FlipFlop = DTypeFlipFlopWithSR;

    Component4094::Component4094():
        BoxComponent(ComponentType::C4094, 16, {
            STROBE, DATA, CLOCK, OE
        }, {
            Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, QS, QSp
        }),
        m_ground{std::make_unique<FalseComponent>()},
        m_invert_clock{std::make_unique<GateNOT>()},
        m_shift_register{std::make_unique<ShiftRegister>()},
        m_qs_prime_flipflop{std::make_unique<FlipFlop>()},
        m_output_transmissions(init_vector_component<GateTransmission>(8)),
        m_output_flipflops(init_vector_component<FlipFlop>(8))
    {
        constexpr std::size_t nb_outputs = 8;
        constexpr std::array<std::size_t, nb_outputs> component_q_outputs{
            this->Q1,
            this->Q2,
            this->Q3,
            this->Q4,
            this->Q5,
            this->Q6,
            this->Q7,
            this->Q8,
        };
        constexpr std::array<std::size_t, nb_outputs> shift_register_outputs{
            ShiftRegister::OUTPUT_Q1,
            ShiftRegister::OUTPUT_Q2,
            ShiftRegister::OUTPUT_Q3,
            ShiftRegister::OUTPUT_Q4,
            ShiftRegister::OUTPUT_Q5,
            ShiftRegister::OUTPUT_Q6,
            ShiftRegister::OUTPUT_Q7,
            ShiftRegister::OUTPUT_Q8,
        };

        setLinkInternal(CLOCK, *m_invert_clock, GateNOT::INPUT);

        setLinkInternal(DATA, *m_shift_register, ShiftRegister::INPUT_DATA_Q1);
        setLinkInternal(CLOCK, *m_shift_register, ShiftRegister::INPUT_CLOCK);

        for (std::size_t index = 0; index < nb_outputs; ++index) {
            m_output_flipflops.at(index)->setLink(FlipFlop::DATA, *m_shift_register, shift_register_outputs.at(index));
            setLinkInternal(STROBE, *m_output_flipflops.at(index), FlipFlop::CLOCK);
            m_output_flipflops.at(index)->setLink(FlipFlop::SET, *m_ground, FalseComponent::OUTPUT);
            m_output_flipflops.at(index)->setLink(FlipFlop::RESET, *m_ground, FalseComponent::OUTPUT);

            m_output_transmissions.at(index)->setLink(GateTransmission::INPUT, *m_output_flipflops.at(index), FlipFlop::Q);
            setLinkInternal(OE, *m_output_transmissions.at(index), GateTransmission::CONTROL);

            setLinkInternal(component_q_outputs.at(index), *m_output_transmissions.at(index), GateTransmission::OUTPUT);
        }

        setLinkInternal(QS, *m_shift_register, shift_register_outputs.back());

        m_qs_prime_flipflop->setLink(FlipFlop::DATA, *m_shift_register, shift_register_outputs.back());
        m_qs_prime_flipflop->setLink(FlipFlop::CLOCK, *m_invert_clock, GateNOT::OUTPUT);
        m_qs_prime_flipflop->setLink(FlipFlop::SET, *m_ground, FalseComponent::OUTPUT);
        m_qs_prime_flipflop->setLink(FlipFlop::RESET, *m_ground, FalseComponent::OUTPUT);

        setLinkInternal(QSp, *m_qs_prime_flipflop, FlipFlop::Q);
    }

    /* ----------------------- ShiftRegister component ----------------------- */

    Component4094::ShiftRegister::ShiftRegister() noexcept:
        ACalculationComponent(ComponentType::ThirdParty, 10, {
            INPUT_DATA_Q1, INPUT_CLOCK
        }, {
            OUTPUT_Q1, OUTPUT_Q2, OUTPUT_Q3, OUTPUT_Q4, OUTPUT_Q5, OUTPUT_Q6, OUTPUT_Q7, OUTPUT_Q8
        })
    {
    }

    void Component4094::ShiftRegister::computeOutputs()
    {
        const Tristate clock = compute(INPUT_CLOCK);
        constexpr std::array<std::size_t, 8> output_pins{
            OUTPUT_Q8, OUTPUT_Q7, OUTPUT_Q6, OUTPUT_Q5, OUTPUT_Q4, OUTPUT_Q3, OUTPUT_Q2, OUTPUT_Q1
        };

        if (clock == UNDEFINED) {
            setAllOutputs(UNDEFINED);
            return;
        }
        if (clock == FALSE)
            return;
        for (std::size_t index = 0; index < output_pins.size() - 1; ++index)
            output(output_pins.at(index)) = output(output_pins.at(index + 1));
        output(OUTPUT_Q1) = compute(INPUT_DATA_Q1);
    }
} // namespace nts
