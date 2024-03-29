/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Component4514
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(Component4514, decoder_component)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/4514_decoder.nts");

    circuit.simulate();

    circuit.setValue("in_0",    "0");
    circuit.setValue("in_1",    "0");
    circuit.setValue("in_2",    "0");
    circuit.setValue("in_3",    "0");
    circuit.setValue("inhibit", "0");
    circuit.setValue("strobe",  "1");

    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_00"), 1);

    circuit.setValue("in_0",    "0");
    circuit.setValue("in_1",    "0");
    circuit.setValue("in_2",    "1");
    circuit.setValue("in_3",    "0");

    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_04"), 1);
}