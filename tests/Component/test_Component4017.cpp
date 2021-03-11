/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_Component4017
*/

#include <algorithm>
#include <vector>
#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(Component4017, johnson_decade_component)
{
    nts::Circuit circuit{"tests/.nts/4017_johnson.nts"};
    std::size_t tick = 0;
    std::vector<std::string> out{
        "out_0",
        "out_1",
        "out_2",
        "out_3",
        "out_4",
        "out_5",
        "out_6",
        "out_7",
        "out_8",
        "out_9"
    };

    circuit.simulate(tick++);
    circuit.setValueForNextTick("in_0", "1");
    circuit.setValueForNextTick("in_1", "0");
    circuit.setValueForNextTick("in_r", "1");
    circuit.simulate(tick++);

    circuit.setValueForNextTick("in_r", "0");
    for (std::size_t index = 0; index < out.size(); ++index) {
        for (std::size_t j = 0; j < out.size(); ++j)
            cr_assert_eq(circuit.output(out.at(j)).getValue(), (index == j));
        cr_assert_eq(circuit.output("out_s").getValue(), (index < 5));
        circuit.simulate(tick++);
    }
}