/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_GateXOR
*/

#include <criterion/criterion.h>
#include "GateXOR.hpp"
#include "Exception.hpp"

Test(GateXOR, truth_table)
{
    nts::GateXOR gate(1, 2);

    cr_assert_eq(gate.operation(nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(gate.operation(nts::TRUE, nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::FALSE, nts::TRUE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE, nts::TRUE), nts::FALSE);
}

Test(GateXOR, handle_undefined_value)
{
    nts::GateXOR gate(1, 2);

    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::TRUE, nts::UNDEFINED), nts::UNDEFINED);
}

Test(GateXOR, handle_same_pin_value)
{
    cr_assert_throw(nts::GateXOR(1, 1), nts::GateInputException);
}
