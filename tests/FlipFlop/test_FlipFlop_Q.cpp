/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_FlipFlop_Q
*/

#include <criterion/criterion.h>
#include "FlipFlopComponent.hpp"

Test(FlipFlopComponent, Q_truth_table)
{
    nts::FlipFlopComponent flipflop;

    cr_assert_eq(flipflop.operation_Q(nts::TRUE,  nts::FALSE, nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(flipflop.operation_Q(nts::TRUE,  nts::TRUE,  nts::FALSE, nts::FALSE), nts::TRUE);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::TRUE,  nts::FALSE, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::FALSE, nts::TRUE,  nts::FALSE), nts::FALSE);
    cr_assert_eq(flipflop.operation_Q(nts::TRUE,  nts::FALSE, nts::TRUE,  nts::FALSE), nts::FALSE);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::TRUE,  nts::TRUE,  nts::FALSE), nts::FALSE);
    cr_assert_eq(flipflop.operation_Q(nts::TRUE,  nts::TRUE,  nts::TRUE,  nts::FALSE), nts::FALSE);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE),  nts::TRUE);
    cr_assert_eq(flipflop.operation_Q(nts::TRUE,  nts::FALSE, nts::FALSE, nts::TRUE),  nts::TRUE);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::TRUE,  nts::FALSE, nts::TRUE),  nts::TRUE);
    cr_assert_eq(flipflop.operation_Q(nts::TRUE,  nts::TRUE,  nts::FALSE, nts::TRUE),  nts::TRUE);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::FALSE, nts::TRUE,  nts::TRUE),  nts::TRUE);
    cr_assert_eq(flipflop.operation_Q(nts::TRUE,  nts::FALSE, nts::TRUE,  nts::TRUE),  nts::TRUE);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::TRUE,  nts::TRUE,  nts::TRUE),  nts::TRUE);
    cr_assert_eq(flipflop.operation_Q(nts::TRUE,  nts::TRUE,  nts::TRUE,  nts::TRUE),  nts::TRUE);
}

Test(FlipFlopComponent, Q_handle_undefined_value)
{
    nts::FlipFlopComponent flipflop;

    cr_assert_eq(flipflop.operation_Q(nts::UNDEFINED,  nts::FALSE, nts::FALSE, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(flipflop.operation_Q(nts::TRUE,  nts::UNDEFINED,  nts::FALSE, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::FALSE, nts::UNDEFINED, nts::FALSE),  nts::UNDEFINED);
    cr_assert_eq(flipflop.operation_Q(nts::FALSE, nts::TRUE,  nts::FALSE, nts::UNDEFINED),  nts::UNDEFINED);
}