/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_FlipFlop
*/

#include <criterion/criterion.h>
#include "DTypeFlipFlopWithSR.hpp"
#include "InputComponent.hpp"

Test(DTypeFlipFlopWithSR, truth_table)
{
    nts::InputComponent cl_clock;
    nts::InputComponent in_data;
    nts::InputComponent in_reset;
    nts::InputComponent in_set;
    nts::DTypeFlipFlopWithSR flipflop;
    std::size_t tick = 0;

    flipflop.setLink(nts::DTypeFlipFlopWithSR::DATA,  in_data,  nts::InputComponent::OUTPUT);
    flipflop.setLink(nts::DTypeFlipFlopWithSR::CLOCK, cl_clock, nts::InputComponent::OUTPUT);
    flipflop.setLink(nts::DTypeFlipFlopWithSR::SET,   in_set,   nts::InputComponent::OUTPUT);
    flipflop.setLink(nts::DTypeFlipFlopWithSR::RESET, in_reset, nts::InputComponent::OUTPUT);

    /* ------------------------------------------------------------------------ */
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::UNDEFINED);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::UNDEFINED);

    cl_clock.setValue(nts::TRUE);
    in_data.setValue(nts::FALSE);
    in_reset.setValue(nts::FALSE);
    in_set.setValue(nts::FALSE);
    flipflop.simulate(tick++);

    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::FALSE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    in_data.setValue(nts::TRUE);
    flipflop.simulate(tick++);

    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::TRUE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);

    /* ------------------------------------------------------------------------ */
    cl_clock.setValue(nts::FALSE);
    in_data.setValue(nts::FALSE);
    in_reset.setValue(nts::TRUE);
    in_set.setValue(nts::FALSE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::FALSE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    cl_clock.setValue(nts::FALSE);
    in_data.setValue(nts::TRUE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::FALSE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    cl_clock.setValue(nts::TRUE);
    in_data.setValue(nts::FALSE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::FALSE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    cl_clock.setValue(nts::TRUE);
    in_data.setValue(nts::TRUE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::FALSE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    /* ------------------------------------------------------------------------ */
    cl_clock.setValue(nts::FALSE);
    in_data.setValue(nts::FALSE);
    in_reset.setValue(nts::FALSE);
    in_set.setValue(nts::TRUE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::TRUE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);

    cl_clock.setValue(nts::FALSE);
    in_data.setValue(nts::TRUE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::TRUE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);

    cl_clock.setValue(nts::TRUE);
    in_data.setValue(nts::FALSE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::TRUE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);

    cl_clock.setValue(nts::TRUE);
    in_data.setValue(nts::TRUE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::TRUE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);

    /* ------------------------------------------------------------------------ */
    cl_clock.setValue(nts::FALSE);
    in_data.setValue(nts::FALSE);
    in_reset.setValue(nts::TRUE);
    in_set.setValue(nts::TRUE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::TRUE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    cl_clock.setValue(nts::FALSE);
    in_data.setValue(nts::TRUE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::TRUE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    cl_clock.setValue(nts::TRUE);
    in_data.setValue(nts::FALSE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::TRUE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    cl_clock.setValue(nts::TRUE);
    in_data.setValue(nts::TRUE);
    flipflop.simulate(tick++);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Q),  nts::TRUE);
    cr_assert_eq(flipflop.compute(nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);
}