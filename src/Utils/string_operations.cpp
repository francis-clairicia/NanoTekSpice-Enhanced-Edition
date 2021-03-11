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
    std::string element;
    std::size_t start = 0;
    std::size_t index = 0;

    while ((index = str.find_first_of(delim, start)) != std::string::npos) {
        element = str.substr(start, index - start);
        if (keep_empty_string || !element.empty())
            array.push_back(element);
        start = index + 1;
    }
    element = str.substr(start);
    if (keep_empty_string || !element.empty())
        array.push_back(element);
    return array;
}

bool string_is_number(const std::string &str)
{
    std::string::const_iterator it = str.begin();
    for (; it != str.end() && std::isdigit(*it); ++it);
    return !str.empty() && it == str.end();
}
