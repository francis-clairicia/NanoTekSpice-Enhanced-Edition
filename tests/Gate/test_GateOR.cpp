/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_GateOR
*/

#include <criterion/criterion.h>
#include "GateOR.hpp"

Test(GateOR, truth_table)
{
    nts::GateOR gate;

    cr_assert_eq(gate.operation(nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(gate.operation(nts::FALSE, nts::TRUE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::TRUE), nts::TRUE);
}

Test(GateOR, handle_undefined_value)
{
    nts::GateOR gate;

    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::FALSE),     nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::FALSE,     nts::UNDEFINED), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::TRUE),      nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE,      nts::UNDEFINED), nts::TRUE);
}
