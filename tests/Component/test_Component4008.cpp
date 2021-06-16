/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Component4008
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(Component4008, adds_two_binary_numbers)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/4008_adder.nts");

    circuit.simulate();

    // Sets in_a to 4 in binary
    circuit.setValue("in_a1", "0");
    circuit.setValue("in_a2", "0");
    circuit.setValue("in_a3", "1");
    circuit.setValue("in_a4", "0");

    // Sets in_b to 13
    circuit.setValue("in_b1", "1");
    circuit.setValue("in_b2", "0");
    circuit.setValue("in_b3", "1");
    circuit.setValue("in_b4", "1");

    // No carry-in
    circuit.setValue("in_c", "0");

    // Simulate
    circuit.simulate();

    // Check outputs to value 17
    cr_assert_eq(circuit.getValue("out_0"), 1);
    cr_assert_eq(circuit.getValue("out_1"), 0);
    cr_assert_eq(circuit.getValue("out_2"), 0);
    cr_assert_eq(circuit.getValue("out_3"), 0);
    cr_assert_eq(circuit.getValue("out_c"), 1);
}