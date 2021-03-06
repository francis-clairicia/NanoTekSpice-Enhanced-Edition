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

using FlipFlop = nts::DTypeFlipFlopWithSR;

nts::Component4094::Component4094() noexcept:
    BoxComponent(ComponentType::C4094, 16, {
        STROBE, DATA, CLOCK, OE
    }, {
        Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, QS, QSp
    }),
    m_ground{std::make_unique<FalseComponent>()},
    m_invert_clock{std::make_unique<GateNOT>()},
    m_shift_register{std::make_unique<ShiftRegister>()},
    m_qs_prime_flipflop{std::make_unique<FlipFlop>()}
{
    const std::array<std::size_t, 8> component_q_outputs{
        this->Q1,
        this->Q2,
        this->Q3,
        this->Q4,
        this->Q5,
        this->Q6,
        this->Q7,
        this->Q8,
    };
    const std::size_t nb_outputs = component_q_outputs.size();
    const std::array<std::size_t, 8> shift_register_outputs{
        ShiftRegister::OUTPUT_Q1,
        ShiftRegister::OUTPUT_Q2,
        ShiftRegister::OUTPUT_Q3,
        ShiftRegister::OUTPUT_Q4,
        ShiftRegister::OUTPUT_Q5,
        ShiftRegister::OUTPUT_Q6,
        ShiftRegister::OUTPUT_Q7,
        ShiftRegister::OUTPUT_Q8,
    };

    init_vector_component<FlipFlop>(m_output_flipflops, nb_outputs);
    init_vector_component<GateTransmission>(m_output_transmissions, nb_outputs);

    m_invert_clock->setLink(GateNOT::INPUT, *this, CLOCK);

    m_shift_register->setLink(ShiftRegister::INPUT_DATA_Q1, *this, DATA);
    m_shift_register->setLink(ShiftRegister::INPUT_CLOCK, *this, CLOCK);

    for (std::size_t index = 0; index < nb_outputs; ++index) {
        m_output_flipflops.at(index)->setLink(FlipFlop::DATA, *m_shift_register, shift_register_outputs.at(index));
        m_output_flipflops.at(index)->setLink(FlipFlop::CLOCK, *this, STROBE);
        m_output_flipflops.at(index)->setLink(FlipFlop::SET, *m_ground, FalseComponent::OUTPUT);
        m_output_flipflops.at(index)->setLink(FlipFlop::RESET, *m_ground, FalseComponent::OUTPUT);

        m_output_transmissions.at(index)->setLink(GateTransmission::INPUT, *m_output_flipflops.at(index), FlipFlop::Q);
        m_output_transmissions.at(index)->setLink(GateTransmission::CONTROL, *this, OE);

        setLinkInternal(component_q_outputs.at(index), *m_output_transmissions.at(index), GateTransmission::OUTPUT);
    }

    setLinkInternal(QS, *m_shift_register, shift_register_outputs.back());

    m_qs_prime_flipflop->setLink(FlipFlop::DATA, *m_shift_register, shift_register_outputs.back());
    m_qs_prime_flipflop->setLink(FlipFlop::CLOCK, *m_invert_clock, GateNOT::OUTPUT);
    m_qs_prime_flipflop->setLink(FlipFlop::SET, *m_ground, FalseComponent::OUTPUT);
    m_qs_prime_flipflop->setLink(FlipFlop::RESET, *m_ground, FalseComponent::OUTPUT);

    setLinkInternal(QSp, *m_qs_prime_flipflop, FlipFlop::Q);
}

nts::Component4094::~Component4094() noexcept
{
}

/* ----------------------- ShiftRegister component ----------------------- */

nts::Component4094::ShiftRegister::ShiftRegister() noexcept:
    ACalculationComponent(ComponentType::ThirdParty, 10, {
        INPUT_DATA_Q1, INPUT_CLOCK
    }, {
        OUTPUT_Q1, OUTPUT_Q2, OUTPUT_Q3, OUTPUT_Q4, OUTPUT_Q5, OUTPUT_Q6, OUTPUT_Q7, OUTPUT_Q8
    })
{
}

nts::Component4094::ShiftRegister::~ShiftRegister() noexcept
{
}

void nts::Component4094::ShiftRegister::computeOutputs()
{
    const nts::Tristate data = compute(INPUT_DATA_Q1);
    const nts::Tristate clock = compute(INPUT_CLOCK);

    if (clock == nts::UNDEFINED) {
        for (auto &pair : m_output_pins)
            pair.second = nts::UNDEFINED;
        return;
    }
    if (clock == nts::FALSE)
        return;
    for (long index = m_output_pin_list.size() - 1; index > 0; --index)
        m_output_pins[m_output_pin_list.at(index)] = m_output_pins.at(m_output_pin_list.at(index - 1));
    m_output_pins[m_output_pin_list.front()] = data;
}