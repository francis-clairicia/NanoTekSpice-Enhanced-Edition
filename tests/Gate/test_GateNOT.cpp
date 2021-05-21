/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_GateNOT
*/

#include <criterion/criterion.h>
#include "GateNOT.hpp"

Test(GateNOT, truth_table)
{
    nts::GateNOT gate;

    cr_assert_eq(gate.operation(nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE),  nts::FALSE);
}

Test(GateNOT, handle_undefined_value)
{
    nts::GateNOT gate;

    cr_assert_eq(gate.operation(nts::UNDEFINED), nts::UNDEFINED);
}
