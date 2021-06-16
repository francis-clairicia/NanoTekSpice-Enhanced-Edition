/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_ConstComponent
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(TrueComponent, always_returns_true)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/true.nts");

    cr_assert_eq(circuit["in"].compute(1), nts::TRUE);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit["in"].compute(1), nts::TRUE);
    cr_assert_eq(circuit.getValue("out"), nts::TRUE);

    circuit.simulate();

    cr_assert_eq(circuit["in"].compute(1), nts::TRUE);
    cr_assert_eq(circuit.getValue("out"), nts::TRUE);
}

Test(FalseComponent, always_returns_false)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/false.nts");

    cr_assert_eq(circuit["in"].compute(1), nts::FALSE);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit["in"].compute(1), nts::FALSE);
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.simulate();

    cr_assert_eq(circuit["in"].compute(1), nts::FALSE);
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);
}