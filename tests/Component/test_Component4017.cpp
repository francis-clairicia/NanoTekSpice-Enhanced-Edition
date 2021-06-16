/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_Component4017
*/

#include <algorithm>
#include <vector>
#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(Component4017, johnson_decade_component)
{
    nts::Circuit circuit = nts::Parser::parse<nts::Circuit>("tests/.nts/4017_johnson.nts");
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

    circuit.simulate();
    circuit.setValue("in_0", "1");
    circuit.setValue("in_1", "0");
    circuit.setValue("in_r", "1");
    circuit.simulate();

    circuit.setValue("in_r", "0");
    for (std::size_t index = 0; index < out.size(); ++index) {
        for (std::size_t j = 0; j < out.size(); ++j)
            cr_assert_eq(circuit.output(out.at(j)).getValue(), (index == j));
        cr_assert_eq(circuit.getValue("out_s"), (index < 5));
        circuit.simulate();
    }
}