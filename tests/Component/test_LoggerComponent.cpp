/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_LoggerComponent
*/

#include <fstream>
#include <criterion/criterion.h>
#include "Circuit.hpp"
#include "Parser.hpp"

Test(LoggerComponent, print_on_log_file)
{
    nts::Circuit circuit = nts::Parser::parse("tests/.nts/logger.nts");

    circuit.simulate();

    circuit.setValue("in_001",  "1");
    circuit.setValue("in_002",  "0");
    circuit.setValue("in_004",  "0");
    circuit.setValue("in_008",  "0");
    circuit.setValue("in_016",  "0");
    circuit.setValue("in_032",  "0");
    circuit.setValue("in_064",  "1");
    circuit.setValue("in_128",  "0");
    circuit.setValue("clock",   "1");
    circuit.setValue("inhibit", "0");

    circuit.simulate();

    /* Does not print if inhibit is True */
    circuit.setValue("inhibit", "1");
    circuit.simulate();

    /* Does not print if clock is False */
    circuit.setValue("inhibit", "0");
    circuit.setValue("clock",   "0");
    circuit.simulate();

    std::ifstream log_stream{"./log.bin"};

    cr_assert(log_stream.good());
    const std::string log((std::istreambuf_iterator<char>(log_stream)), std::istreambuf_iterator<char>());
    log_stream.close();

    cr_assert_str_eq(log.c_str(), "A");
}