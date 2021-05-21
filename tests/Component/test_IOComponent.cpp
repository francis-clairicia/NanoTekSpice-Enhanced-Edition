/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_IOComponent
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(InputComponent, get_an_input_from_prompt)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/input_output.nts");

    cr_assert_eq(circuit.input("in").getValue(), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit.input("in").getValue(), nts::UNDEFINED);

    circuit.setValueForNextTick("in", "0");
    circuit.simulate();

    cr_assert_eq(circuit.input("in").getValue(), nts::FALSE);

    circuit.setValueForNextTick("in", "1");
    circuit.simulate();

    cr_assert_eq(circuit.input("in").getValue(), nts::TRUE);

    circuit.setValueForNextTick("in", "U");
    circuit.simulate();

    cr_assert_eq(circuit.input("in").getValue(), nts::UNDEFINED);
}

Test(OutputComponent, get_value_computed_from_its_pin)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/input_output.nts");

    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.simulate();

    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in", "0");
    circuit.simulate();

    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in", "1");
    circuit.simulate();

    cr_assert_eq(circuit.output("out").getValue(), nts::TRUE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in", "U");
    circuit.simulate();

    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);
}