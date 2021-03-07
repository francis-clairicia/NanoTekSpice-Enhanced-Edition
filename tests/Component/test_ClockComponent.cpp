/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_ClockComponent
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(ClockComponent, work_same_as_input)
{
    nts::Circuit circuit{"tests/.nts/clock.nts"};
    std::size_t tick = 0;

    cr_assert_eq(circuit["cl"].compute(1), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::UNDEFINED);

    circuit.setValueForNextTick("cl", "0");
    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::FALSE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.setValueForNextTick("cl", "1");
    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::TRUE);
    cr_assert_eq(circuit["out"].compute(1), nts::TRUE);

    circuit.setValueForNextTick("cl", "U");
    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::UNDEFINED);
}

Test(ClockComponent, invert_state_at_each_simulate)
{
    nts::Circuit circuit{"tests/.nts/clock.nts"};
    std::size_t tick = 0;

    circuit.simulate(tick++);

    circuit.setValueForNextTick("cl", "0");
    cr_assert_eq(circuit["cl"].compute(1), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::FALSE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::TRUE);
    cr_assert_eq(circuit["out"].compute(1), nts::TRUE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::FALSE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::TRUE);
    cr_assert_eq(circuit["out"].compute(1), nts::TRUE);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::FALSE);
    cr_assert_eq(circuit["out"].compute(1), nts::FALSE);
}

Test(ClockComponent, does_not_invert_undefined_state)
{
    nts::Circuit circuit{"tests/.nts/clock.nts"};
    std::size_t tick = 0;

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::UNDEFINED);

    circuit.simulate(tick++);

    cr_assert_eq(circuit["cl"].compute(1), nts::UNDEFINED);
    cr_assert_eq(circuit["out"].compute(1), nts::UNDEFINED);
}