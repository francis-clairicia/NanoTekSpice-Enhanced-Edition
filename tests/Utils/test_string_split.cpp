/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_string_split
*/

#include <criterion/criterion.h>
#include "string_operations.hpp"

Test(string_split_by_delimiters, create_a_vector_of_splitted_str)
{
    std::vector<std::string> list = string_split_by_delimiters("Hello:World:!", ":");

    cr_assert_eq(list.size(), 3);
    cr_assert_str_eq(list[0].data(), "Hello");
    cr_assert_str_eq(list[1].data(), "World");
    cr_assert_str_eq(list[2].data(), "!");
}

Test(string_split_by_delimiters, handle_successive_delimiter)
{
    std::vector<std::string> list = string_split_by_delimiters("Hello:::World:::!", ":");

    cr_assert_eq(list.size(), 3);
    cr_assert_str_eq(list[0].data(), "Hello");
    cr_assert_str_eq(list[1].data(), "World");
    cr_assert_str_eq(list[2].data(), "!");
}

Test(string_split_by_delimiters, keep_empty_string_on_successive_delimiter)
{
    std::vector<std::string> list = string_split_by_delimiters("Hello:::World:::!", ":", true);

    cr_assert_eq(list.size(), 7);
    cr_assert_str_eq(list[0].data(), "Hello");
    cr_assert_str_empty(list[1].data());
    cr_assert_str_empty(list[2].data());
    cr_assert_str_eq(list[3].data(), "World");
    cr_assert_str_empty(list[4].data());
    cr_assert_str_empty(list[5].data());
    cr_assert_str_eq(list[6].data(), "!");
}

Test(string_split_by_delimiters, return_a_one_size_vector_if_there_is_no_delimiter)
{
    std::vector<std::string> list = string_split_by_delimiters("Hello World", ":");

    cr_assert_eq(list.size(), 1);
    cr_assert_str_eq(list[0].data(), "Hello World");
}

Test(string_split_by_delimiters, return_empty_vector_for_empty_string)
{
    std::vector<std::string> list = string_split_by_delimiters("", ":");

    cr_assert_eq(list.size(), 0);
}

Test(string_split_by_delimiters, return_one_size_vector_for_empty_string_if_keep_empty_string)
{
    std::vector<std::string> list = string_split_by_delimiters("", ":", true);

    cr_assert_eq(list.size(), 1);
    cr_assert_str_empty(list[0].data());
}

