/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** test_trim_trailing_whitespace
*/

#include <criterion/criterion.h>
#include "string_operations.hpp"

Test(trim_trailing_whitespace, remove_all_space_and_tab_at_front_and_back_of_a_string)
{
    std::string str{"  \tHello World    \t   "};

    trim_trailing_whitespace(str);
    cr_assert_str_eq(str.data(), "Hello World");
}

Test(trim_trailing_whitespace, give_an_empty_string_if_str_contains_only_whitespaces)
{
    std::string str{"    \t    \t     \t "};

    trim_trailing_whitespace(str);
    cr_assert_str_empty(str.data());
}

Test(trim_trailing_whitespace, does_nothing_if_str_is_already_trimmed)
{
    std::string str{"Hello World"};

    trim_trailing_whitespace(str);
    cr_assert_str_eq(str.data(), "Hello World");
}

Test(trim_trailing_whitespace, does_nothing_on_empty_string)
{
    std::string str;

    trim_trailing_whitespace(str);
    cr_assert_str_empty(str.data());
}
