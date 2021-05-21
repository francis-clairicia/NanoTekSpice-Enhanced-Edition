/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** string_operations
*/

#ifndef STRING_OPERATIONS_HPP_
#define STRING_OPERATIONS_HPP_

#include <string>
#include <vector>

bool string_endswith(const std::string &str, const std::string &to_find);
void trim_trailing_whitespace(std::string &str);
std::vector<std::string> string_split_by_delimiters(const std::string &str, const std::string &delim, bool keep_empty_string = false);
bool string_is_number(const std::string &str);

#endif /* !STRING_OPERATIONS_HPP_ */
