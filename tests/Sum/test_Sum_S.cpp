/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_Sum_S
*/

#include <criterion/criterion.h>
#include "SumComponent.hpp"

Test(SumComponent, S_truth_table)
{
    nts::SumComponent sum;

    cr_assert_eq(sum.operationS(nts::FALSE, nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(sum.operationS(nts::TRUE,  nts::FALSE, nts::FALSE), nts::TRUE);
    cr_assert_eq(sum.operationS(nts::FALSE, nts::TRUE,  nts::FALSE), nts::TRUE);
    cr_assert_eq(sum.operationS(nts::TRUE,  nts::TRUE,  nts::FALSE), nts::FALSE);
    cr_assert_eq(sum.operationS(nts::FALSE, nts::FALSE, nts::TRUE),  nts::TRUE);
    cr_assert_eq(sum.operationS(nts::TRUE,  nts::FALSE, nts::TRUE),  nts::FALSE);
    cr_assert_eq(sum.operationS(nts::FALSE, nts::TRUE,  nts::TRUE),  nts::FALSE);
    cr_assert_eq(sum.operationS(nts::TRUE,  nts::TRUE,  nts::TRUE),  nts::TRUE);
}

Test(SumComponent, S_handle_undefined_value)
{
    nts::SumComponent sum;

    cr_assert_eq(sum.operationS(nts::UNDEFINED, nts::FALSE, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(sum.operationS(nts::TRUE,  nts::UNDEFINED, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(sum.operationS(nts::FALSE, nts::TRUE,  nts::UNDEFINED), nts::UNDEFINED);
}