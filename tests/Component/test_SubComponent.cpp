/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_SubComponent
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(SubComponent, substract_two_numbers)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/sub.nts");

    circuit.simulate();

    // Sets in_a to 13
    circuit.setValue("in_a1", "1");
    circuit.setValue("in_a2", "0");
    circuit.setValue("in_a3", "1");
    circuit.setValue("in_a4", "1");

    // Sets in_b to 4 in binary
    circuit.setValue("in_b1", "0");
    circuit.setValue("in_b2", "0");
    circuit.setValue("in_b3", "1");
    circuit.setValue("in_b4", "0");

    // No carry-in
    circuit.setValue("in_c", "0");

    // Simulate
    circuit.simulate();

    // Check outputs to value 9
    cr_assert_eq(circuit.getValue("out_0"), 1);
    cr_assert_eq(circuit.getValue("out_1"), 0);
    cr_assert_eq(circuit.getValue("out_2"), 0);
    cr_assert_eq(circuit.getValue("out_3"), 1);
    cr_assert_eq(circuit.getValue("out_c"), 0);
}