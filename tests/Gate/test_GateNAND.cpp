/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_GateNAND
*/

#include <criterion/criterion.h>
#include "GateNAND.hpp"

Test(GateNAND, truth_table)
{
    nts::GateNAND gate;

    cr_assert_eq(gate.operation(nts::FALSE, nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::FALSE, nts::TRUE),  nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::TRUE),  nts::FALSE);
}

Test(GateNAND, handle_undefined_value)
{
    nts::GateNAND gate;

    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::TRUE),      nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::TRUE,      nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::FALSE),     nts::TRUE);
    cr_assert_eq(gate.operation(nts::FALSE,     nts::UNDEFINED), nts::TRUE);
}
