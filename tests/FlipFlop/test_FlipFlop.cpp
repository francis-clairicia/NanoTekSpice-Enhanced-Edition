/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_FlipFlop
*/

#include <criterion/criterion.h>
#include "FlipFlopComponent.hpp"
#include "ConstComponent.hpp"

static nts::Tristate compute(nts::FlipFlopComponent &flipflop,
                             nts::InputComponent &clock,
                             nts::InputComponent &data,
                             nts::InputComponent &reset,
                             nts::InputComponent &set,
                             std::size_t output_pin)
{
    static std::size_t tick = 0;

    flipflop.setLink(nts::FlipFlopComponent::CLOCK, clock, 1);
    flipflop.setLink(nts::FlipFlopComponent::DATA, data, 1);
    flipflop.setLink(nts::FlipFlopComponent::RESET, reset, 1);
    flipflop.setLink(nts::FlipFlopComponent::SET, set, 1);
    flipflop.simulate(++tick);
    return flipflop.compute(output_pin);
}

Test(FlipFlopComponent, Q_truth_table_set_and_reset)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::FlipFlopComponent flipflop;

    cr_expect_eq(compute(flipflop, c_false, c_false, c_true,  c_false, nts::FlipFlopComponent::Q), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_false, c_false, c_false, c_true, nts::FlipFlopComponent::Q), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_false, c_false, c_true,  c_true, nts::FlipFlopComponent::Q), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_false, c_true,  c_true,  c_false, nts::FlipFlopComponent::Q), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_false, c_true,  c_false, c_true, nts::FlipFlopComponent::Q), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_false, c_true,  c_true,  c_true, nts::FlipFlopComponent::Q), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_true,  c_false, c_true,  c_false, nts::FlipFlopComponent::Q), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_true,  c_false, c_false, c_true, nts::FlipFlopComponent::Q), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_true,  c_false, c_true,  c_true, nts::FlipFlopComponent::Q), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_true,  c_false, nts::FlipFlopComponent::Q), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_false, c_true, nts::FlipFlopComponent::Q), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_true,  c_true, nts::FlipFlopComponent::Q), nts::TRUE);
}

Test(FlipFlopComponent, Qnot_truth_table_set_and_reset)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::FlipFlopComponent flipflop;

    cr_expect_eq(compute(flipflop, c_false, c_false, c_true,  c_false, nts::FlipFlopComponent::Qn), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_false, c_false, c_false, c_true, nts::FlipFlopComponent::Qn), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_false, c_false, c_true,  c_true, nts::FlipFlopComponent::Qn), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_false, c_true,  c_true,  c_false, nts::FlipFlopComponent::Qn), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_false, c_true,  c_false, c_true, nts::FlipFlopComponent::Qn), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_false, c_true,  c_true,  c_true, nts::FlipFlopComponent::Qn), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_true,  c_false, c_true,  c_false, nts::FlipFlopComponent::Qn), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_true,  c_false, c_false, c_true, nts::FlipFlopComponent::Qn), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_true,  c_false, c_true,  c_true, nts::FlipFlopComponent::Qn), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_true,  c_false, nts::FlipFlopComponent::Qn), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_false, c_true, nts::FlipFlopComponent::Qn), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_true,  c_true, nts::FlipFlopComponent::Qn), nts::TRUE);
}
