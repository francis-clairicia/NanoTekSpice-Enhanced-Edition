/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_Sum
*/

#include <criterion/criterion.h>
#include "SumComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"

static nts::Tristate compute(nts::SumComponent &sum,
                             nts::InputComponent &a,
                             nts::InputComponent &b,
                             nts::InputComponent &c,
                             std::size_t output_pin)
{
    static std::size_t tick = 0;

    sum.setLink(1, a, 1);
    sum.setLink(2, b, 1);
    sum.setLink(3, c, 1);
    sum.simulate(++tick);
    return sum.compute(output_pin);
}

Test(SumComponent, Co_truth_table)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::SumComponent sum;
    std::size_t Co_output = 4;

    cr_assert_eq(compute(sum, c_false, c_false, c_false, Co_output), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_false, c_false, Co_output), nts::FALSE);
    cr_assert_eq(compute(sum, c_false, c_true,  c_false, Co_output), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_true,  c_false, Co_output), nts::TRUE);
    cr_assert_eq(compute(sum, c_false, c_false, c_true,  Co_output), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_false, c_true,  Co_output), nts::TRUE);
    cr_assert_eq(compute(sum, c_false, c_true,  c_true,  Co_output), nts::TRUE);
    cr_assert_eq(compute(sum, c_true,  c_true,  c_true,  Co_output), nts::TRUE);
}

Test(SumComponent, Co_handle_undefined_value)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::InputComponent c_undefined;
    nts::SumComponent sum;
    std::size_t Co_output = 4;

    cr_assert_eq(compute(sum, c_undefined, c_false,     c_false,     Co_output), nts::UNDEFINED);
    cr_assert_eq(compute(sum, c_true,      c_undefined, c_false,     Co_output), nts::UNDEFINED);
    cr_assert_eq(compute(sum, c_false,     c_true,      c_undefined, Co_output), nts::UNDEFINED);
}

Test(SumComponent, S_truth_table)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::SumComponent sum;
    std::size_t S_output = 5;

    cr_assert_eq(compute(sum, c_false, c_false, c_false, S_output), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_false, c_false, S_output), nts::TRUE);
    cr_assert_eq(compute(sum, c_false, c_true,  c_false, S_output), nts::TRUE);
    cr_assert_eq(compute(sum, c_true,  c_true,  c_false, S_output), nts::FALSE);
    cr_assert_eq(compute(sum, c_false, c_false, c_true,  S_output), nts::TRUE);
    cr_assert_eq(compute(sum, c_true,  c_false, c_true,  S_output), nts::FALSE);
    cr_assert_eq(compute(sum, c_false, c_true,  c_true,  S_output), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_true,  c_true,  S_output), nts::TRUE);
}

Test(SumComponent, S_handle_undefined_value)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::InputComponent c_undefined;
    nts::SumComponent sum;
    std::size_t S_output = 5;

    cr_assert_eq(compute(sum, c_undefined, c_false,     c_false,     S_output), nts::UNDEFINED);
    cr_assert_eq(compute(sum, c_true,      c_undefined, c_false,     S_output), nts::UNDEFINED);
    cr_assert_eq(compute(sum, c_false,     c_true,      c_undefined, S_output), nts::UNDEFINED);
}
