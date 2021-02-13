/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_GateNAND
*/

#include <criterion/criterion.h>
#include "GateNAND.hpp"
#include "Exception.hpp"

Test(GateNAND, truth_table)
{
    nts::GateNAND gate(1, 2);

    cr_assert_eq(gate.operation(nts::FALSE, nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE, nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::FALSE, nts::TRUE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE, nts::TRUE), nts::FALSE);
}

Test(GateNAND, handle_undefined_value)
{
    nts::GateNAND gate(1, 2);

    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::TRUE, nts::UNDEFINED), nts::UNDEFINED);
}

Test(GateNAND, handle_same_pin_value)
{
    cr_assert_throw(nts::GateNAND(1, 1), nts::GateInputException);
}
