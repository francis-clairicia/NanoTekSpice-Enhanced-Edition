/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_Component4008
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(Component4008, adds_two_binary_numbers)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/4008_adder.nts");

    circuit.simulate();

    // Sets in_a to 4 in binary
    circuit.setValueForNextTick("in_a1", "0");
    circuit.setValueForNextTick("in_a2", "0");
    circuit.setValueForNextTick("in_a3", "1");
    circuit.setValueForNextTick("in_a4", "0");

    // Sets in_b to 13
    circuit.setValueForNextTick("in_b1", "1");
    circuit.setValueForNextTick("in_b2", "0");
    circuit.setValueForNextTick("in_b3", "1");
    circuit.setValueForNextTick("in_b4", "1");

    // No carry-in
    circuit.setValueForNextTick("in_c", "0");

    // Simulate
    circuit.simulate();

    // Check outputs to value 17
    cr_assert_eq(circuit.output("out_0").getValue(), 1);
    cr_assert_eq(circuit.output("out_1").getValue(), 0);
    cr_assert_eq(circuit.output("out_2").getValue(), 0);
    cr_assert_eq(circuit.output("out_3").getValue(), 0);
    cr_assert_eq(circuit.output("out_c").getValue(), 1);
}