/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_ClockComponent
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(ClockComponent, work_same_as_input)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/clock.nts");
    std::size_t tick = 0;

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.setValueForNextTick("cl", "0");
    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);

    circuit.setValueForNextTick("cl", "1");
    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::TRUE);
    cr_assert_eq(circuit.output("out").getValue(), nts::TRUE);

    circuit.setValueForNextTick("cl", "U");
    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);
}

Test(ClockComponent, invert_state_at_each_simulate)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/clock.nts");
    std::size_t tick = 0;

    circuit.simulate(tick++);

    circuit.setValueForNextTick("cl", "0");
    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::TRUE);
    cr_assert_eq(circuit.output("out").getValue(), nts::TRUE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::TRUE);
    cr_assert_eq(circuit.output("out").getValue(), nts::TRUE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::FALSE);
    cr_assert_eq(circuit.output("out").getValue(), nts::FALSE);
}

Test(ClockComponent, does_not_invert_undefined_state)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/clock.nts");
    std::size_t tick = 0;

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.output("out").getValue(), nts::UNDEFINED);
}