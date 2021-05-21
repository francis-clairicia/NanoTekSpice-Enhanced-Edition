/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Component4040
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(Component4040, counter_component)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/4040_counter.nts");
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

    circuit.simulate();

    circuit.setValueForNextTick("cl_clock", "0");
    circuit.setValueForNextTick("in_reset", "1");
    circuit.simulate();

    circuit.setValueForNextTick("in_reset", "0");
    for (std::size_t count = 0; count < 4096; ++count) {
        for (std::size_t bit = 0; bit < out.size(); ++bit)
            cr_assert_eq(circuit.output(out.at(bit)).getValue(), ((count & (1UL << bit)) >> bit));
        circuit.simulate();
    }
}