/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_GateINVERTER
*/

#include <criterion/criterion.h>
#include "GateINVERTER.hpp"
#include "Exception.hpp"

Test(GateINVERTER, truth_table)
{
    nts::GateINVERTER gate;

    cr_assert_eq(gate.operation(nts::FALSE), nts::TRUE);
    cr_assert_eq(gate.operation(nts::TRUE), nts::FALSE);
}

Test(GateINVERTER, handle_undefined_value)
{
    nts::GateINVERTER gate;

    cr_assert_eq(gate.operation(nts::UNDEFINED), nts::UNDEFINED);
}
