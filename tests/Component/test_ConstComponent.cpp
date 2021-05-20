/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_ConstComponent
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(TrueComponent, always_returns_true)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/true.nts");

    cr_assert_eq(circuit["in"].compute(1), nts::TRUE);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit["in"].compute(1), nts::TRUE);
    cr_assert_eq(circuit.output("out").getValue(), nts::TRUE);

    circuit.simulate();

    cr_assert_eq(circuit["in"].compute(1), nts::TRUE);
    cr_assert_eq(circuit.output("out").getValue(), nts::TRUE);
}

Test(FalseComponent, always_returns_false)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/false.nts");

    cr_assert_eq(circuit["in"].compute(1), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit["in"].compute(1), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);

    circuit.simulate();

    cr_assert_eq(circuit["in"].compute(1), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);
}