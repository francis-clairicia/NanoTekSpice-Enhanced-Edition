/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_Circuit
*/

#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Circuit.hpp"
#include "BadComponentNameException.hpp"
#include "BadComponentTypeException.hpp"

Test(Circuit, create_and_handle_nanotekspice_circuit)
{
    nts::Circuit circuit;

    cr_redirect_stdout();
    circuit.addComponent("input", "in");
    circuit.addComponent("output", "out");
    circuit["in"].setLink(1, circuit["out"], 1);
    circuit["out"].setLink(1, circuit["in"], 1);
    circuit.simulate(0);

    circuit.display(0);
    std::cout.flush();
    cr_assert_stdout_neq_str("");
}

Test(Circuit, throw_for_non_existing_component_type)
{
    nts::Circuit circuit;

    cr_assert_throw(circuit.addComponent("nreioanaozjnz", "hello"), nts::BadComponentTypeException);
}

Test(Circuit, throw_for_non_existing_component_name)
{
    nts::Circuit circuit;

    circuit.addComponent("input", "in");
    cr_assert_throw(circuit.setValueForNextTick("unknown", "1"), nts::BadComponentNameException);
    cr_assert_throw(circuit["unknown"], nts::BadComponentNameException);
}

Test(Circuit, dump_components)
{
    nts::Circuit circuit;
    circuit.addComponent("input", "in");

    cr_redirect_stdout();
    circuit.dump();
    std::cout.flush();
    cr_assert_stdout_neq_str("");
}