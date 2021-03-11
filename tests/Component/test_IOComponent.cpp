/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_IOComponent
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(InputComponent, get_an_input_from_prompt)
{
    nts::Circuit circuit{"tests/.nts/input_output.nts"};
    std::size_t tick = 0;

    cr_assert_eq(circuit.input("in").getValue(), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("in").getValue(), nts::UNDEFINED);

    circuit.setValueForNextTick("in", "0");
    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("in").getValue(), nts::FALSE);

    circuit.setValueForNextTick("in", "1");
    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("in").getValue(), nts::TRUE);

    circuit.setValueForNextTick("in", "U");
    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("in").getValue(), nts::UNDEFINED);
}

Test(OutputComponent, get_value_computed_from_its_pin)
{
    nts::Circuit circuit{"tests/.nts/input_output.nts"};
    std::size_t tick = 0;

    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in", "0");
    circuit.simulate(tick++);

    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in", "1");
    circuit.simulate(tick++);

    cr_assert_eq(circuit.output("out").getValue(), nts::TRUE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in", "U");
    circuit.simulate(tick++);

    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);
}