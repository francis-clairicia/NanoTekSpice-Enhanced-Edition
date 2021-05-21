/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_GateAND
*/

#include <criterion/criterion.h>
#include "GateAND.hpp"

Test(GateAND, truth_table)
{
    nts::GateAND gate;

    cr_assert_eq(gate.operation(nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(gate.operation(nts::FALSE, nts::TRUE),  nts::FALSE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::FALSE), nts::FALSE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::TRUE),  nts::TRUE);
}

Test(GateAND, handle_undefined_value)
{
    nts::GateAND gate;

    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::TRUE),      nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::TRUE,      nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::FALSE),     nts::FALSE);
    cr_assert_eq(gate.operation(nts::FALSE,     nts::UNDEFINED), nts::FALSE);
}
