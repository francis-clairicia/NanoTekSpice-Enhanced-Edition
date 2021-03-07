/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_Component4040
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(Component4040, counter_component)
{
    nts::Circuit circuit{"tests/.nts/4040_counter.nts"};
    std::size_t tick = 0;
    std::vector<std::string> out{
        "out_00",
        "out_01",
        "out_02",
        "out_03",
        "out_04",
        "out_05",
        "out_06",
        "out_07",
        "out_08",
        "out_09",
        "out_10",
        "out_11"
    };

    circuit.simulate(tick++);

    circuit.setValueForNextTick("cl_clock", "0");
    circuit.setValueForNextTick("in_reset", "1");
    circuit.simulate(tick++);

    circuit.setValueForNextTick("in_reset", "0");
    for (std::size_t count = 0; count < 4096; ++count) {
        for (std::size_t bit = 0; bit < out.size(); ++bit)
            cr_assert_eq(circuit[out.at(bit)].compute(1), ((count & (1UL << bit)) >> bit));
        circuit.simulate(tick++);
    }
}