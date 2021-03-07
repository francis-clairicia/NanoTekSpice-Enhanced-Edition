/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_and_or_not
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(and_or_not, gate_linking_circuit)
{
    nts::Circuit circuit{"tests/.nts/advanced/and-or-not.nts"};
    std::size_t tick = 0;

    circuit.simulate(tick++);
    cr_assert_eq(circuit["out"].compute(1), nts::UNDEFINED);

    circuit.setValueForNextTick("in_a", "0");
    circuit.setValueForNextTick("in_b", "0");
    circuit.setValueForNextTick("in_c", "0");
    circuit.simulate(tick++);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in_a", "1");
    circuit.setValueForNextTick("in_b", "0");
    circuit.setValueForNextTick("in_c", "0");
    circuit.simulate(tick++);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in_a", "0");
    circuit.setValueForNextTick("in_b", "1");
    circuit.setValueForNextTick("in_c", "0");
    circuit.simulate(tick++);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in_a", "1");
    circuit.setValueForNextTick("in_b", "1");
    circuit.setValueForNextTick("in_c", "0");
    circuit.simulate(tick++);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in_a", "0");
    circuit.setValueForNextTick("in_b", "0");
    circuit.setValueForNextTick("in_c", "1");
    circuit.simulate(tick++);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in_a", "1");
    circuit.setValueForNextTick("in_b", "0");
    circuit.setValueForNextTick("in_c", "1");
    circuit.simulate(tick++);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("in_a", "0");
    circuit.setValueForNextTick("in_b", "1");
    circuit.setValueForNextTick("in_c", "1");
    circuit.simulate(tick++);
    cr_assert_eq(circuit["out"].compute(1), nts::TRUE);

    circuit.setValueForNextTick("in_a", "1");
    circuit.setValueForNextTick("in_b", "1");
    circuit.setValueForNextTick("in_c", "1");
    circuit.simulate(tick++);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);
}