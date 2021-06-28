/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Sub
*/

#include <criterion/criterion.h>
#include "TwoBitsSubComponent.hpp"
#include "InputComponent.hpp"

Test(TwoBitsSubComponent, Bo_truth_table)
{
    nts::InputComponent in_x;
    nts::InputComponent in_y;
    nts::InputComponent in_b;
    nts::TwoBitsSubComponent sub;
    std::size_t tick = 0;

    sub.setLink(nts::TwoBitsSubComponent::Xi, in_x, nts::InputComponent::OUTPUT);
    sub.setLink(nts::TwoBitsSubComponent::Yi, in_y, nts::InputComponent::OUTPUT);
    sub.setLink(nts::TwoBitsSubComponent::Bi, in_b, nts::InputComponent::OUTPUT);

    in_x.setValue(nts::FALSE);
    in_y.setValue(nts::FALSE);
    in_b.setValue(nts::FALSE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Bo), nts::FALSE);

    in_x.setValue(nts::TRUE);
    in_y.setValue(nts::FALSE);
    in_b.setValue(nts::FALSE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Bo), nts::FALSE);

    in_x.setValue(nts::FALSE);
    in_y.setValue(nts::TRUE);
    in_b.setValue(nts::FALSE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Bo), nts::TRUE);

    in_x.setValue(nts::TRUE);
    in_y.setValue(nts::TRUE);
    in_b.setValue(nts::FALSE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Bo), nts::FALSE);

    in_x.setValue(nts::FALSE);
    in_y.setValue(nts::FALSE);
    in_b.setValue(nts::TRUE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Bo), nts::TRUE);

    in_x.setValue(nts::TRUE);
    in_y.setValue(nts::FALSE);
    in_b.setValue(nts::TRUE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Bo), nts::FALSE);

    in_x.setValue(nts::FALSE);
    in_y.setValue(nts::TRUE);
    in_b.setValue(nts::TRUE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Bo), nts::TRUE);

    in_x.setValue(nts::TRUE);
    in_y.setValue(nts::TRUE);
    in_b.setValue(nts::TRUE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Bo), nts::TRUE);
}

Test(TwoBitsSubComponent, Diff_truth_table)
{
    nts::InputComponent in_x;
    nts::InputComponent in_y;
    nts::InputComponent in_b;
    nts::TwoBitsSubComponent sub;
    std::size_t tick = 0;

    sub.setLink(nts::TwoBitsSubComponent::Xi, in_x, nts::InputComponent::OUTPUT);
    sub.setLink(nts::TwoBitsSubComponent::Yi, in_y, nts::InputComponent::OUTPUT);
    sub.setLink(nts::TwoBitsSubComponent::Bi, in_b, nts::InputComponent::OUTPUT);

    in_x.setValue(nts::FALSE);
    in_y.setValue(nts::FALSE);
    in_b.setValue(nts::FALSE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Diff), nts::FALSE);

    in_x.setValue(nts::TRUE);
    in_y.setValue(nts::FALSE);
    in_b.setValue(nts::FALSE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Diff), nts::TRUE);

    in_x.setValue(nts::FALSE);
    in_y.setValue(nts::TRUE);
    in_b.setValue(nts::FALSE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Diff), nts::TRUE);

    in_x.setValue(nts::TRUE);
    in_y.setValue(nts::TRUE);
    in_b.setValue(nts::FALSE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Diff), nts::FALSE);

    in_x.setValue(nts::FALSE);
    in_y.setValue(nts::FALSE);
    in_b.setValue(nts::TRUE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Diff), nts::TRUE);

    in_x.setValue(nts::TRUE);
    in_y.setValue(nts::FALSE);
    in_b.setValue(nts::TRUE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Diff), nts::FALSE);

    in_x.setValue(nts::FALSE);
    in_y.setValue(nts::TRUE);
    in_b.setValue(nts::TRUE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Diff), nts::FALSE);

    in_x.setValue(nts::TRUE);
    in_y.setValue(nts::TRUE);
    in_b.setValue(nts::TRUE);
    sub.simulate(tick++);
    cr_assert_eq(sub.compute(nts::TwoBitsSubComponent::Diff), nts::TRUE);
}