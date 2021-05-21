/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_string_is_number
*/

#include <criterion/criterion.h>
#include "string_operations.hpp"

Test(string_is_number, check_if_a_string_only_digit_characters)
{
    cr_assert(string_is_number("123"));
    cr_assert_not(string_is_number("12c"));
}

Test(string_is_number, does_not_accept_negative_numbers)
{
    cr_assert_not(string_is_number("-42"));
}

Test(string_is_number, is_false_for_empty_string)
{
    cr_assert_not(string_is_number(""));
}