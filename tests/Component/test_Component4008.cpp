/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_Component4008
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(Component4008, adds_two_binary_numbers)
{
    nts::Circuit circuit{"tests/.nts/4008_adder.nts"};
    std::size_t tick = 0;

    circuit.simulate(tick++);

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
    circuit.simulate(tick++);

    // Check outputs to value 17
    cr_assert_eq(circuit["out_0"].compute(1), 1);
    cr_assert_eq(circuit["out_1"].compute(1), 0);
    cr_assert_eq(circuit["out_2"].compute(1), 0);
    cr_assert_eq(circuit["out_3"].compute(1), 0);
    cr_assert_eq(circuit["out_c"].compute(1), 1);
}