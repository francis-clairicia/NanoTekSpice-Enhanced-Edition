/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_FlipFlop
*/

#include <criterion/criterion.h>
#include "DTypeFlipFlopWithSR.hpp"
#include "ConstComponent.hpp"

static nts::Tristate compute(nts::DTypeFlipFlopWithSR &flipflop,
                             nts::IComponent &clock,
                             nts::IComponent &data,
                             nts::IComponent &reset,
                             nts::IComponent &set,
                             std::size_t output_pin)
{
    static std::size_t tick = 0;

    flipflop.setLink(nts::DTypeFlipFlopWithSR::CLOCK, clock, 1);
    flipflop.setLink(nts::DTypeFlipFlopWithSR::DATA, data, 1);
    flipflop.setLink(nts::DTypeFlipFlopWithSR::RESET, reset, 1);
    flipflop.setLink(nts::DTypeFlipFlopWithSR::SET, set, 1);
    flipflop.simulate(++tick);
    return flipflop.compute(output_pin);
}

Test(DTypeFlipFlopWithSR, Q_truth_table)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::DTypeFlipFlopWithSR flipflop;

    /* Memory initialized */
    cr_expect_eq(compute(flipflop, c_false, c_false, c_false, c_false, nts::DTypeFlipFlopWithSR::Q), nts::UNDEFINED);
    cr_expect_eq(compute(flipflop, c_false, c_true, c_false,  c_false, nts::DTypeFlipFlopWithSR::Q), nts::UNDEFINED);

    cr_expect_eq(compute(flipflop, c_true, c_false, c_false, c_false, nts::DTypeFlipFlopWithSR::Q), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_true, c_true, c_false,  c_false, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);

    /* Keep in memory */
    cr_expect_eq(compute(flipflop, c_false, c_false, c_false, c_false, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_false, c_true, c_false,  c_false, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_false, c_false, c_true,  c_false, nts::DTypeFlipFlopWithSR::Q), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_false, c_false, c_false, c_true, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_false, c_false, c_true,  c_true, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_false, c_true,  c_true,  c_false, nts::DTypeFlipFlopWithSR::Q), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_false, c_true,  c_false, c_true, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_false, c_true,  c_true,  c_true, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_true,  c_false, c_true,  c_false, nts::DTypeFlipFlopWithSR::Q), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_true,  c_false, c_false, c_true, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_true,  c_false, c_true,  c_true, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_true,  c_false, nts::DTypeFlipFlopWithSR::Q), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_false, c_true, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_true,  c_true, nts::DTypeFlipFlopWithSR::Q), nts::TRUE);
}

Test(DTypeFlipFlopWithSR, Qnot_truth_table)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::DTypeFlipFlopWithSR flipflop;

    /* Memory initialized */
    cr_expect_eq(compute(flipflop, c_false, c_false, c_false, c_false, nts::DTypeFlipFlopWithSR::Qn), nts::UNDEFINED);
    cr_expect_eq(compute(flipflop, c_false, c_true, c_false,  c_false, nts::DTypeFlipFlopWithSR::Qn), nts::UNDEFINED);

    cr_expect_eq(compute(flipflop, c_true, c_false, c_false, c_false, nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_true, c_true, c_false,  c_false, nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);

    /* Keep in memory */
    cr_expect_eq(compute(flipflop, c_false, c_false, c_false, c_false, nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_false, c_true, c_false,  c_false, nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);

    cr_expect_eq(compute(flipflop, c_false, c_false, c_true,  c_false, nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_false, c_false, c_false, c_true, nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_false, c_false, c_true,  c_true, nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_false, c_true,  c_true,  c_false, nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_false, c_true,  c_false, c_true, nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_false, c_true,  c_true,  c_true, nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_true,  c_false, c_true,  c_false, nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_true,  c_false, c_false, c_true, nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_true,  c_false, c_true,  c_true, nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);

    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_true,  c_false, nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);
    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_false, c_true, nts::DTypeFlipFlopWithSR::Qn), nts::FALSE);
    cr_expect_eq(compute(flipflop, c_true,  c_true,  c_true,  c_true, nts::DTypeFlipFlopWithSR::Qn), nts::TRUE);
}
