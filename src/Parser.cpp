/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Parser
*/

#include <fstream>
#include "Parser.hpp"
#include "Exception.hpp"

static bool string_endswith(const std::string &str, const std::string &to_find)
{
    return str.length() > to_find.length() && str.compare(str.length() - to_find.length(), to_find.length(), to_find) == 0;
}

nts::Parser::Parser(const std::string &circuit_file, nts::ComponentFactory &factory):
    m_file(circuit_file), m_factory(factory)
{
    if (!string_endswith(m_file, ".nts"))
        throw nts::FileException(m_file, "Circuit file must have .nts extension");
}

nts::Parser::~Parser()
{
}

void nts::Parser::parse()
{
    std::ifstream file(m_file);

    if (!file.is_open())
        throw FileException(m_file, "Cannot open file");

    std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    m_factory["a"] = m_factory.createComponent("input");
    m_factory["b"] = m_factory.createComponent("output");
}