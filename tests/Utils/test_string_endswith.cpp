/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_string_endswith
*/

#include <criterion/criterion.h>
#include "string_operations.hpp"

Test(string_endswith, check_whether_the_end_of_a_string_match_to_a_string)
{
    cr_assert(string_endswith("Hello World", "World"));
    cr_assert_not(string_endswith("Hello World", "Hello"));
    cr_assert(string_endswith("Hello World", "Hello World"));
    cr_assert_not(string_endswith("Hello World", "Hello Worldddd"));
}