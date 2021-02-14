/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_GateNOT
*/

#include <criterion/criterion.h>
#include "GateNOT.hpp"
#include "Exception.hpp"

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
