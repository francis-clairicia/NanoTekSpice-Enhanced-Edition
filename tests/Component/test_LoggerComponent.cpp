/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_LoggerComponent
*/

#include <fstream>
#include <criterion/criterion.h>
#include "Circuit.hpp"

Test(LoggerComponent, print_on_log_file)
{
    nts::Circuit circuit{"tests/.nts/logger.nts"};
    std::size_t tick = 0;

    circuit.simulate(tick++);

    circuit.setValueForNextTick("in_001",  "1");
    circuit.setValueForNextTick("in_002",  "0");
    circuit.setValueForNextTick("in_004",  "0");
    circuit.setValueForNextTick("in_008",  "0");
    circuit.setValueForNextTick("in_016",  "0");
    circuit.setValueForNextTick("in_032",  "0");
    circuit.setValueForNextTick("in_064",  "1");
    circuit.setValueForNextTick("in_128",  "0");
    circuit.setValueForNextTick("clock",   "1");
    circuit.setValueForNextTick("inhibit", "0");

    circuit.simulate(tick++);

    /* Does not print if inhibit is True */
    circuit.setValueForNextTick("inhibit", "1");
    circuit.simulate(tick++);

    /* Does not print if clock is False */
    circuit.setValueForNextTick("inhibit", "0");
    circuit.setValueForNextTick("clock",   "0");
    circuit.simulate(tick++);

    std::ifstream log_stream{"./log.bin"};

    cr_assert(log_stream.good());
    const std::string log((std::istreambuf_iterator<char>(log_stream)), std::istreambuf_iterator<char>());
    log_stream.close();

    cr_assert_str_eq(log.c_str(), "A");
}