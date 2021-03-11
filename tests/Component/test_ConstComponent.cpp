/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_ConstComponent
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(TrueComponent, always_returns_true)
{
    nts::Circuit circuit{"tests/.nts/true.nts"};
    std::size_t tick = 0;

    cr_assert_eq(circuit["in"].compute(1), nts::TRUE);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["in"].compute(1), nts::TRUE);
    cr_assert_eq(circuit.output("out").getValue(), nts::TRUE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["in"].compute(1), nts::TRUE);
    cr_assert_eq(circuit.output("out").getValue(), nts::TRUE);
}

Test(FalseComponent, always_returns_false)
{
    nts::Circuit circuit{"tests/.nts/false.nts"};
    std::size_t tick = 0;

    cr_assert_eq(circuit["in"].compute(1), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["in"].compute(1), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["in"].compute(1), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);
}