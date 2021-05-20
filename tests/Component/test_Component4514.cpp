/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_Component4514
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(Component4514, decoder_component)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/4514_decoder.nts");

    circuit.simulate();

    circuit.setValueForNextTick("in_0",    "0");
    circuit.setValueForNextTick("in_1",    "0");
    circuit.setValueForNextTick("in_2",    "0");
    circuit.setValueForNextTick("in_3",    "0");
    circuit.setValueForNextTick("inhibit", "0");
    circuit.setValueForNextTick("strobe",  "1");

    circuit.simulate();

    cr_assert_eq(circuit.output("out_00").getValue(), 1);

    circuit.setValueForNextTick("in_0",    "0");
    circuit.setValueForNextTick("in_1",    "0");
    circuit.setValueForNextTick("in_2",    "1");
    circuit.setValueForNextTick("in_3",    "0");

    circuit.simulate();

    cr_assert_eq(circuit.output("out_04").getValue(), 1);
}