/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_Sum
*/

#include <criterion/criterion.h>
#include "SumComponent.hpp"
#include "ConstComponent.hpp"

static nts::Tristate compute(nts::SumComponent &sum,
                             nts::IComponent &a,
                             nts::IComponent &b,
                             nts::IComponent &c,
                             std::size_t output_pin)
{
    static std::size_t tick = 0;

    sum.setLink(nts::SumComponent::Ai, a, 1);
    sum.setLink(nts::SumComponent::Bi, b, 1);
    sum.setLink(nts::SumComponent::Ci, c, 1);
    sum.simulate(++tick);
    return sum.compute(output_pin);
}

Test(SumComponent, Co_truth_table)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::SumComponent sum;

    cr_assert_eq(compute(sum, c_false, c_false, c_false, nts::SumComponent::Co), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_false, c_false, nts::SumComponent::Co), nts::FALSE);
    cr_assert_eq(compute(sum, c_false, c_true,  c_false, nts::SumComponent::Co), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_true,  c_false, nts::SumComponent::Co), nts::TRUE);
    cr_assert_eq(compute(sum, c_false, c_false, c_true,  nts::SumComponent::Co), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_false, c_true,  nts::SumComponent::Co), nts::TRUE);
    cr_assert_eq(compute(sum, c_false, c_true,  c_true,  nts::SumComponent::Co), nts::TRUE);
    cr_assert_eq(compute(sum, c_true,  c_true,  c_true,  nts::SumComponent::Co), nts::TRUE);
}

Test(SumComponent, S_truth_table)
{
    nts::TrueComponent c_true;
    nts::FalseComponent c_false;
    nts::SumComponent sum;

    cr_assert_eq(compute(sum, c_false, c_false, c_false, nts::SumComponent::Si), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_false, c_false, nts::SumComponent::Si), nts::TRUE);
    cr_assert_eq(compute(sum, c_false, c_true,  c_false, nts::SumComponent::Si), nts::TRUE);
    cr_assert_eq(compute(sum, c_true,  c_true,  c_false, nts::SumComponent::Si), nts::FALSE);
    cr_assert_eq(compute(sum, c_false, c_false, c_true,  nts::SumComponent::Si), nts::TRUE);
    cr_assert_eq(compute(sum, c_true,  c_false, c_true,  nts::SumComponent::Si), nts::FALSE);
    cr_assert_eq(compute(sum, c_false, c_true,  c_true,  nts::SumComponent::Si), nts::FALSE);
    cr_assert_eq(compute(sum, c_true,  c_true,  c_true,  nts::SumComponent::Si), nts::TRUE);
}
