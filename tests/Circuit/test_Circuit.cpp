/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Circuit
*/

#include <iostream>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Circuit.hpp"
#include "BadComponentNameException.hpp"
#include "BadComponentTypeException.hpp"
#include "ComponentNameOverride.hpp"

Test(Circuit, create_and_handle_nanotekspice_circuit)
{
    nts::Circuit circuit;

    cr_redirect_stdout();
    circuit.addComponent("input", "in");
    circuit.addComponent("output", "out");
    circuit["in"].setLink(1, circuit["out"], 1);
    circuit["out"].setLink(1, circuit["in"], 1);
    circuit.simulate();

    cr_assert_eq(circuit.getTick(), 0);
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
    cr_assert_throw(circuit.setValue("unknown", "1"), nts::BadComponentNameException);
    cr_assert_throw(circuit["unknown"], nts::BadComponentNameException);
}

Test(Circuit, throw_for_adding_component_existing_component_name)
{
    nts::Circuit circuit;

    circuit.addComponent("input", "in");
    cr_assert_throw(circuit.addComponent("input", "in"), nts::ComponentNameOverride);
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