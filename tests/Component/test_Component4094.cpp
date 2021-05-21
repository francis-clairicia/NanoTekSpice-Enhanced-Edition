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
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/4094_shift.nts");

    circuit.simulate();

    circuit.setValueForNextTick("clock", "1");
    circuit.setValueForNextTick("data", "1");

    circuit.simulate();
    cr_assert_eq(circuit.output("out_0").getValue(), 1);

    circuit.setValueForNextTick("data", "0");

    circuit.simulate();
    cr_assert_eq(circuit.output("out_0").getValue(), 0);
    cr_assert_eq(circuit.output("out_1").getValue(), 1);

    circuit.simulate();
    cr_assert_eq(circuit.output("out_0").getValue(), 0);
    cr_assert_eq(circuit.output("out_1").getValue(), 0);
    cr_assert_eq(circuit.output("out_2").getValue(), 1);

    for (std::size_t index = 3; index < 8; ++index)
        circuit.simulate();
    cr_assert_eq(circuit.output("out_0").getValue(), 0);
    cr_assert_eq(circuit.output("out_1").getValue(), 0);
    cr_assert_eq(circuit.output("out_2").getValue(), 0);
    cr_assert_eq(circuit.output("out_3").getValue(), 0);
    cr_assert_eq(circuit.output("out_4").getValue(), 0);
    cr_assert_eq(circuit.output("out_5").getValue(), 0);
    cr_assert_eq(circuit.output("out_6").getValue(), 0);
    cr_assert_eq(circuit.output("out_7").getValue(), 1);
    cr_assert_eq(circuit.output("out_qs").getValue(), 1);
    cr_assert_eq(circuit.output("out_qe").getValue(), nts::UNDEFINED);
}