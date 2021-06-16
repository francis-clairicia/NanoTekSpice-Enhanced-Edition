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
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/input_output.nts");

    cr_assert_eq(circuit.input("in").getValue(), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit.input("in").getValue(), nts::UNDEFINED);

    circuit.setValue("in", "0");
    circuit.simulate();

    cr_assert_eq(circuit.input("in").getValue(), nts::FALSE);

    circuit.setValue("in", "1");
    circuit.simulate();

    cr_assert_eq(circuit.input("in").getValue(), nts::TRUE);

    circuit.setValue("in", "U");
    circuit.simulate();

    cr_assert_eq(circuit.input("in").getValue(), nts::UNDEFINED);
}

Test(OutputComponent, get_value_computed_from_its_pin)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/input_output.nts");

    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.simulate();

    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValue("in", "0");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out"), nts::FALSE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValue("in", "1");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out"), nts::TRUE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValue("in", "U");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);
}