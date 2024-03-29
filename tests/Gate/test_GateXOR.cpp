/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_GateXOR
*/

#include <criterion/criterion.h>
#include "GateXOR.hpp"

Test(GateXOR, truth_table)
{
    nts::GateXOR gate;

    cr_assert_eq(gate.operation(nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(gate.operation(nts::FALSE, nts::TRUE),  nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::TRUE),  nts::FALSE);
}

Test(GateXOR, handle_undefined_value)
{
    nts::GateXOR gate;

    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::FALSE),     nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::FALSE,     nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::TRUE),      nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::TRUE,      nts::UNDEFINED), nts::UNDEFINED);
}
