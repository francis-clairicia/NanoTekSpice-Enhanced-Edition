/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Component4094
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(Component4094, shift_register_component)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/4094_shift.nts");

    circuit.simulate();

    circuit.setValue("clock", "1");
    circuit.setValue("data", "1");

    circuit.simulate();
    cr_assert_eq(circuit.getValue("out_0"), 1);

    circuit.setValue("data", "0");

    circuit.simulate();
    cr_assert_eq(circuit.getValue("out_0"), 0);
    cr_assert_eq(circuit.getValue("out_1"), 1);

    circuit.simulate();
    cr_assert_eq(circuit.getValue("out_0"), 0);
    cr_assert_eq(circuit.getValue("out_1"), 0);
    cr_assert_eq(circuit.getValue("out_2"), 1);

    for (std::size_t index = 3; index < 8; ++index)
        circuit.simulate();
    cr_assert_eq(circuit.getValue("out_0"), 0);
    cr_assert_eq(circuit.getValue("out_1"), 0);
    cr_assert_eq(circuit.getValue("out_2"), 0);
    cr_assert_eq(circuit.getValue("out_3"), 0);
    cr_assert_eq(circuit.getValue("out_4"), 0);
    cr_assert_eq(circuit.getValue("out_5"), 0);
    cr_assert_eq(circuit.getValue("out_6"), 0);
    cr_assert_eq(circuit.getValue("out_7"), 1);
    cr_assert_eq(circuit.getValue("out_qs"), 1);
    cr_assert_eq(circuit.getValue("out_qe"), nts::UNDEFINED);
}