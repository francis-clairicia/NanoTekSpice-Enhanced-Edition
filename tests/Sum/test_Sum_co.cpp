/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_Sum_co
*/

#include <criterion/criterion.h>
#include "SumComponent.hpp"

Test(SumComponent, Co_truth_table)
{
    nts::SumComponent sum;

    cr_assert_eq(sum.operationCo(nts::FALSE, nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(sum.operationCo(nts::TRUE,  nts::FALSE, nts::FALSE), nts::FALSE);
    cr_assert_eq(sum.operationCo(nts::FALSE, nts::TRUE,  nts::FALSE), nts::FALSE);
    cr_assert_eq(sum.operationCo(nts::TRUE,  nts::TRUE,  nts::FALSE), nts::TRUE);
    cr_assert_eq(sum.operationCo(nts::FALSE, nts::FALSE, nts::TRUE),  nts::FALSE);
    cr_assert_eq(sum.operationCo(nts::TRUE,  nts::FALSE, nts::TRUE),  nts::TRUE);
    cr_assert_eq(sum.operationCo(nts::FALSE, nts::TRUE,  nts::TRUE),  nts::TRUE);
    cr_assert_eq(sum.operationCo(nts::TRUE,  nts::TRUE,  nts::TRUE),  nts::TRUE);
}

Test(SumComponent, Co_handle_undefined_value)
{
    nts::SumComponent sum;

    cr_assert_eq(sum.operationCo(nts::UNDEFINED, nts::FALSE, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(sum.operationCo(nts::TRUE,  nts::UNDEFINED, nts::FALSE), nts::UNDEFINED);
    cr_assert_eq(sum.operationCo(nts::FALSE, nts::TRUE,  nts::UNDEFINED), nts::UNDEFINED);
}