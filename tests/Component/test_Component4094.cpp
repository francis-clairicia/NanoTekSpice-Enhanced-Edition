/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_Component4094
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(Component4094, shift_register_component)
{
    nts::Circuit circuit{"tests/.nts/4094_shift.nts"};
    std::size_t tick = 0;

    circuit.simulate(tick++);

    circuit.setValueForNextTick("clock", "1");
    circuit.setValueForNextTick("data", "1");

    circuit.simulate(tick++);
    cr_assert_eq(circuit["out_0"].compute(1), 1);

    circuit.setValueForNextTick("data", "0");

    circuit.simulate(tick++);
    cr_assert_eq(circuit["out_0"].compute(1), 0);
    cr_assert_eq(circuit["out_1"].compute(1), 1);

    circuit.simulate(tick++);
    cr_assert_eq(circuit["out_0"].compute(1), 0);
    cr_assert_eq(circuit["out_1"].compute(1), 0);
    cr_assert_eq(circuit["out_2"].compute(1), 1);

    for (std::size_t index = 3; index < 8; ++index)
        circuit.simulate(tick++);
    cr_assert_eq(circuit["out_0"].compute(1), 0);
    cr_assert_eq(circuit["out_1"].compute(1), 0);
    cr_assert_eq(circuit["out_2"].compute(1), 0);
    cr_assert_eq(circuit["out_3"].compute(1), 0);
    cr_assert_eq(circuit["out_4"].compute(1), 0);
    cr_assert_eq(circuit["out_5"].compute(1), 0);
    cr_assert_eq(circuit["out_6"].compute(1), 0);
    cr_assert_eq(circuit["out_7"].compute(1), 1);
    cr_assert_eq(circuit["out_qs"].compute(1), 1);
    cr_assert_eq(circuit["out_qe"].compute(1), nts::UNDEFINED);
}