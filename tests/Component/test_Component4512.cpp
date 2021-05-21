/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Component4512
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(Component4512, selector_component)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/4512_selector.nts");

    circuit.simulate();

    circuit.setValue("in_a", "0");
    circuit.setValue("in_b", "0");
    circuit.setValue("in_c", "0");
    circuit.setValue("in_0", "1");
    circuit.setValue("enable", "0");
    circuit.setValue("inhibit", "0");

    circuit.simulate();
    cr_assert_eq(circuit.getValue("out_data"), 1);

    /* returns Hi-Z (UNDEFINED) if OE is TRUE */
    circuit.setValue("enable", "1");
    circuit.simulate();
    cr_assert_eq(circuit.getValue("out_data"), nts::UNDEFINED);
}