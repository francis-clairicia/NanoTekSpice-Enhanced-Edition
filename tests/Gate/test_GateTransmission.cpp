/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_GateTransmission
*/

#include <criterion/criterion.h>
#include "GateTransmission.hpp"

Test(GateTransmission, truth_table)
{
    nts::GateTransmission gate;

    cr_assert_eq(gate.operation(nts::TRUE,  nts::TRUE),  nts::TRUE);
    cr_assert_eq(gate.operation(nts::FALSE, nts::TRUE),  nts::FALSE);
    cr_assert_eq(gate.operation(nts::TRUE,  nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::FALSE, nts::FALSE), nts::UNDEFINED);
}

Test(GateTransmission, handle_undefined_value)
{
    nts::GateTransmission gate;

    cr_assert_eq(gate.operation(nts::UNDEFINED, nts::TRUE), nts::UNDEFINED);
    cr_assert_eq(gate.operation(nts::TRUE, nts::UNDEFINED), nts::UNDEFINED);
}