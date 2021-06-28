/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Sum
*/

#include <criterion/criterion.h>
#include "SumComponent.hpp"
#include "InputComponent.hpp"

Test(SumComponent, Co_truth_table)
{
    nts::InputComponent in_a;
    nts::InputComponent in_b;
    nts::InputComponent in_c;
    nts::SumComponent sum;
    std::size_t tick = 0;

    sum.setLink(nts::SumComponent::Ai, in_a, nts::InputComponent::OUTPUT);
    sum.setLink(nts::SumComponent::Bi, in_b, nts::InputComponent::OUTPUT);
    sum.setLink(nts::SumComponent::Ci, in_c, nts::InputComponent::OUTPUT);

    in_a.setValue(nts::FALSE);
    in_b.setValue(nts::FALSE);
    in_c.setValue(nts::FALSE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Co), nts::FALSE);

    in_a.setValue(nts::TRUE);
    in_b.setValue(nts::FALSE);
    in_c.setValue(nts::FALSE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Co), nts::FALSE);

    in_a.setValue(nts::FALSE);
    in_b.setValue(nts::TRUE);
    in_c.setValue(nts::FALSE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Co), nts::FALSE);

    in_a.setValue(nts::TRUE);
    in_b.setValue(nts::TRUE);
    in_c.setValue(nts::FALSE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Co), nts::TRUE);

    in_a.setValue(nts::FALSE);
    in_b.setValue(nts::FALSE);
    in_c.setValue(nts::TRUE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Co), nts::FALSE);

    in_a.setValue(nts::TRUE);
    in_b.setValue(nts::FALSE);
    in_c.setValue(nts::TRUE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Co), nts::TRUE);

    in_a.setValue(nts::FALSE);
    in_b.setValue(nts::TRUE);
    in_c.setValue(nts::TRUE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Co), nts::TRUE);

    in_a.setValue(nts::TRUE);
    in_b.setValue(nts::TRUE);
    in_c.setValue(nts::TRUE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Co), nts::TRUE);
}

Test(SumComponent, S_truth_table)
{
    nts::InputComponent in_a;
    nts::InputComponent in_b;
    nts::InputComponent in_c;
    nts::SumComponent sum;
    std::size_t tick = 0;

    sum.setLink(nts::SumComponent::Ai, in_a, nts::InputComponent::OUTPUT);
    sum.setLink(nts::SumComponent::Bi, in_b, nts::InputComponent::OUTPUT);
    sum.setLink(nts::SumComponent::Ci, in_c, nts::InputComponent::OUTPUT);

    in_a.setValue(nts::FALSE);
    in_b.setValue(nts::FALSE);
    in_c.setValue(nts::FALSE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Si), nts::FALSE);

    in_a.setValue(nts::TRUE);
    in_b.setValue(nts::FALSE);
    in_c.setValue(nts::FALSE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Si), nts::TRUE);

    in_a.setValue(nts::FALSE);
    in_b.setValue(nts::TRUE);
    in_c.setValue(nts::FALSE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Si), nts::TRUE);

    in_a.setValue(nts::TRUE);
    in_b.setValue(nts::TRUE);
    in_c.setValue(nts::FALSE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Si), nts::FALSE);

    in_a.setValue(nts::FALSE);
    in_b.setValue(nts::FALSE);
    in_c.setValue(nts::TRUE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Si), nts::TRUE);

    in_a.setValue(nts::TRUE);
    in_b.setValue(nts::FALSE);
    in_c.setValue(nts::TRUE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Si), nts::FALSE);

    in_a.setValue(nts::FALSE);
    in_b.setValue(nts::TRUE);
    in_c.setValue(nts::TRUE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Si), nts::FALSE);

    in_a.setValue(nts::TRUE);
    in_b.setValue(nts::TRUE);
    in_c.setValue(nts::TRUE);
    sum.simulate(tick++);
    cr_assert_eq(sum.compute(nts::SumComponent::Si), nts::TRUE);
}
