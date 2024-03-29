/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_GateNOR
*/

#include <criterion/criterion.h>
#include "GateNOR.hpp"

Test(GateNOR, truth_table)
{
    nts::GateNOR gate;

    cr_assert_eq(gate.operation(nts::FALSE, nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::FALSE, nts::TRUE),  nts::FALSE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::FALSE), nts::FALSE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::TRUE),  nts::FALSE);
}

Test(GateNOR, handle_undefined_value)
{
    nts::GateNOR gate;

    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::FALSE),     nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::FALSE,     nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::TRUE),      nts::FALSE);
    cr_assert_eq(gate.operation(nts::TRUE,      nts::UNDEFINED), nts::FALSE);
}
