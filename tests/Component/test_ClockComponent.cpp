/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_ClockComponent
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(ClockComponent, work_same_as_input)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/clock.nts");

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);

    circuit.setValue("cl", "0");
    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::FALSE);
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.setValue("cl", "1");
    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::TRUE);
    cr_assert_eq(circuit.getValue("out"), nts::TRUE);

    circuit.setValue("cl", "U");
    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);
}

Test(ClockComponent, invert_state_at_each_simulate)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/clock.nts");

    circuit.simulate();

    circuit.setValue("cl", "0");
    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::FALSE);
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::TRUE);
    cr_assert_eq(circuit.getValue("out"), nts::TRUE);

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::FALSE);
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::TRUE);
    cr_assert_eq(circuit.getValue("out"), nts::TRUE);

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::FALSE);
    cr_assert_eq(circuit.getValue("out"), nts::FALSE);
}

Test(ClockComponent, does_not_invert_undefined_state)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/clock.nts");

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);

    circuit.simulate();

    cr_assert_eq(circuit.input("cl").getValue(), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out"), nts::UNDEFINED);
}