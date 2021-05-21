/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_and_or_not
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(and_or_not, gate_linking_circuit)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/advanced/and-or-not.nts");

    circuit.simulate();
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);

    circuit.setValue("in_a", "0");
    circuit.setValue("in_b", "0");
    circuit.setValue("in_c", "0");
    circuit.simulate();
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.setValue("in_a", "1");
    circuit.setValue("in_b", "0");
    circuit.setValue("in_c", "0");
    circuit.simulate();
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.setValue("in_a", "0");
    circuit.setValue("in_b", "1");
    circuit.setValue("in_c", "0");
    circuit.simulate();
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.setValue("in_a", "1");
    circuit.setValue("in_b", "1");
    circuit.setValue("in_c", "0");
    circuit.simulate();
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.setValue("in_a", "0");
    circuit.setValue("in_b", "0");
    circuit.setValue("in_c", "1");
    circuit.simulate();
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.setValue("in_a", "1");
    circuit.setValue("in_b", "0");
    circuit.setValue("in_c", "1");
    circuit.simulate();
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.setValue("in_a", "0");
    circuit.setValue("in_b", "1");
    circuit.setValue("in_c", "1");
    circuit.simulate();
    cr_assert_eq(circuit.getValue("out"), nts::TRUE);

    circuit.setValue("in_a", "1");
    circuit.setValue("in_b", "1");
    circuit.setValue("in_c", "1");
    circuit.simulate();
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);
}