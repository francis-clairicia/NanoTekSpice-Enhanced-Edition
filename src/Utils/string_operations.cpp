/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** string_operations
*/

#include <algorithm>
#include "string_operations.hpp"

bool string_endswith(const std::string &str, const std::string &to_find)
{
    return str.length() >= to_find.length() && str.compare(str.length() - to_find.length(), to_find.length(), to_find) == 0;
}

void trim_trailing_whitespace(std::string &str)
{
    auto predicate = [](unsigned char c) {return !std::isspace(c);};

    str.erase(str.begin(), std::find_if(str.begin(), str.end(), predicate));
    str.erase(std::find_if(str.rbegin(), str.rend(), predicate).base(), str.end());
}

std::vector<std::string> string_split_by_delimiters(const std::string &str, const std::string &delim, bool keep_empty_string)
{
    std::vector<std::string> array;
    std::size_t start = 0;
    std::size_t index = 0;
    auto add_to_array = [&array, &keep_empty_string](std::string element)
    {
        if (keep_empty_string || !element.empty())
            array.emplace_back(std::move(element));
    };

    while ((index = str.find_first_of(delim, start)) != std::string::npos) {
        add_to_array(str.substr(start, index - start));
        start = index + 1;
    }
    add_to_array(str.substr(start));
    return array;
}

bool string_is_number(const std::string &str)
{
    std::string::const_iterator it = str.begin();
    for (; it != str.end() && std::isdigit(*it); ++it);
    return !str.empty() && it == str.end();
}
