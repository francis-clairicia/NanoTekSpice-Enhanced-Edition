/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_GateAND
*/

#include <criterion/criterion.h>
#include "GateAND.hpp"
#include "Exception.hpp"

Test(GateAND, truth_table)
{
    nts::GateAND gate(1, 2);

    cr_assert_eq(gate.operation(nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(gate.operation(nts::TRUE, nts::FALSE), nts::FALSE);
    cr_assert_eq(gate.operation(nts::FALSE, nts::TRUE), nts::FALSE);
    cr_assert_eq(gate.operation(nts::TRUE, nts::TRUE), nts::TRUE);
}

Test(GateAND, handle_undefined_value)
{
    nts::GateAND gate(1, 2);

    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::TRUE, nts::UNDEFINED), nts::UNDEFINED);
}

Test(GateAND, handle_same_pin_value)
{
    cr_assert_throw(nts::GateAND(1, 1), nts::GateInputException);
}
