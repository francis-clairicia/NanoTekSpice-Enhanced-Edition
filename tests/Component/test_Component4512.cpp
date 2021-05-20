/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
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

    circuit.setValueForNextTick("in_a", "0");
    circuit.setValueForNextTick("in_b", "0");
    circuit.setValueForNextTick("in_c", "0");
    circuit.setValueForNextTick("in_0", "1");
    circuit.setValueForNextTick("enable", "0");
    circuit.setValueForNextTick("inhibit", "0");

    circuit.simulate();
    cr_assert_eq(circuit.output("out_data").getValue(), 1);

    /* returns Hi-Z (UNDEFINED) if OE is TRUE */
    circuit.setValueForNextTick("enable", "1");
    circuit.simulate();
    cr_assert_eq(circuit.output("out_data").getValue(), nts::UNDEFINED);
}