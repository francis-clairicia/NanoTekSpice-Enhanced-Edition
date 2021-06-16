/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Component4801
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

namespace
{
    void set_default_values(nts::Circuit &circuit)
    {
        circuit.setValue("enable", "1");
        circuit.setValue("write",  "0");
        circuit.setValue("read",   "1");
        circuit.setValue("addr_0", "0");
        circuit.setValue("addr_1", "0");
        circuit.setValue("addr_2", "0");
        circuit.setValue("addr_3", "0");
        circuit.setValue("addr_4", "0");
        circuit.setValue("addr_5", "0");
        circuit.setValue("addr_6", "0");
        circuit.setValue("addr_7", "0");
        circuit.setValue("addr_8", "0");
        circuit.setValue("addr_9", "0");
        circuit.setValue("in_0",   "0");
        circuit.setValue("in_1",   "0");
        circuit.setValue("in_2",   "0");
        circuit.setValue("in_3",   "0");
        circuit.setValue("in_4",   "0");
        circuit.setValue("in_5",   "0");
        circuit.setValue("in_6",   "0");
        circuit.setValue("in_7",   "0");
    }
} // namespace


Test(Component4801, random_access_memory_component)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/4801_ram.nts");
    circuit.simulate();

    set_default_values(circuit);
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), 0);
    cr_assert_eq(circuit.getValue("out_1"), 0);
    cr_assert_eq(circuit.getValue("out_2"), 0);
    cr_assert_eq(circuit.getValue("out_3"), 0);
    cr_assert_eq(circuit.getValue("out_4"), 0);
    cr_assert_eq(circuit.getValue("out_5"), 0);
    cr_assert_eq(circuit.getValue("out_6"), 0);
    cr_assert_eq(circuit.getValue("out_7"), 0);

    circuit.setValue("in_0", "0");
    circuit.setValue("in_1", "1");
    circuit.setValue("in_2", "0");
    circuit.setValue("in_3", "0");
    circuit.setValue("in_4", "1");
    circuit.setValue("in_5", "1");
    circuit.setValue("in_6", "1");
    circuit.setValue("in_7", "0");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), 0);
    cr_assert_eq(circuit.getValue("out_1"), 0);
    cr_assert_eq(circuit.getValue("out_2"), 0);
    cr_assert_eq(circuit.getValue("out_3"), 0);
    cr_assert_eq(circuit.getValue("out_4"), 0);
    cr_assert_eq(circuit.getValue("out_5"), 0);
    cr_assert_eq(circuit.getValue("out_6"), 0);
    cr_assert_eq(circuit.getValue("out_7"), 0);

    circuit.setValue("write", "1");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), 0);
    cr_assert_eq(circuit.getValue("out_1"), 1);
    cr_assert_eq(circuit.getValue("out_2"), 0);
    cr_assert_eq(circuit.getValue("out_3"), 0);
    cr_assert_eq(circuit.getValue("out_4"), 1);
    cr_assert_eq(circuit.getValue("out_5"), 1);
    cr_assert_eq(circuit.getValue("out_6"), 1);
    cr_assert_eq(circuit.getValue("out_7"), 0);

    circuit.setValue("write", "0");
    circuit.setValue("in_0",  "0");
    circuit.setValue("in_1",  "0");
    circuit.setValue("in_2",  "0");
    circuit.setValue("in_3",  "0");
    circuit.setValue("in_4",  "0");
    circuit.setValue("in_5",  "0");
    circuit.setValue("in_6",  "0");
    circuit.setValue("in_7",  "0");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), 0);
    cr_assert_eq(circuit.getValue("out_1"), 1);
    cr_assert_eq(circuit.getValue("out_2"), 0);
    cr_assert_eq(circuit.getValue("out_3"), 0);
    cr_assert_eq(circuit.getValue("out_4"), 1);
    cr_assert_eq(circuit.getValue("out_5"), 1);
    cr_assert_eq(circuit.getValue("out_6"), 1);
    cr_assert_eq(circuit.getValue("out_7"), 0);

    circuit.setValue("read", "0");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_1"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_2"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_3"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_4"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_5"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_6"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_7"), nts::UNDEFINED);
}

Test(Component4801, disabled_ram_component)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/4801_ram.nts");
    circuit.simulate();

    set_default_values(circuit);
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), 0);
    cr_assert_eq(circuit.getValue("out_1"), 0);
    cr_assert_eq(circuit.getValue("out_2"), 0);
    cr_assert_eq(circuit.getValue("out_3"), 0);
    cr_assert_eq(circuit.getValue("out_4"), 0);
    cr_assert_eq(circuit.getValue("out_5"), 0);
    cr_assert_eq(circuit.getValue("out_6"), 0);
    cr_assert_eq(circuit.getValue("out_7"), 0);

    circuit.setValue("enable", "0");

    circuit.setValue("in_0", "0");
    circuit.setValue("in_1", "1");
    circuit.setValue("in_2", "0");
    circuit.setValue("in_3", "0");
    circuit.setValue("in_4", "1");
    circuit.setValue("in_5", "1");
    circuit.setValue("in_6", "1");
    circuit.setValue("in_7", "0");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_1"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_2"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_3"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_4"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_5"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_6"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_7"), nts::UNDEFINED);

    circuit.setValue("write", "1");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_1"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_2"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_3"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_4"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_5"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_6"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_7"), nts::UNDEFINED);

    circuit.setValue("write", "0");
    circuit.setValue("in_0",  "0");
    circuit.setValue("in_1",  "0");
    circuit.setValue("in_2",  "0");
    circuit.setValue("in_3",  "0");
    circuit.setValue("in_4",  "0");
    circuit.setValue("in_5",  "0");
    circuit.setValue("in_6",  "0");
    circuit.setValue("in_7",  "0");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_1"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_2"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_3"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_4"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_5"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_6"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_7"), nts::UNDEFINED);

    circuit.setValue("read", "0");
    circuit.simulate();

    cr_assert_eq(circuit.getValue("out_0"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_1"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_2"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_3"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_4"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_5"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_6"), nts::UNDEFINED);
    cr_assert_eq(circuit.getValue("out_7"), nts::UNDEFINED);
}