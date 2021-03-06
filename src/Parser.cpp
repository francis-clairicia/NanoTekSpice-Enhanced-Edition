/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Parser
*/

#include <fstream>
#include "string_operations.hpp"
#include "Parser.hpp"
#include "FileException.hpp"
#include "SyntaxException.hpp"
#include "BadComponentNameException.hpp"
#include "BadComponentTypeException.hpp"
#include "BadPinException.hpp"
#include "ComponentLinkException.hpp"
#include "ComponentTypeUnknownException.hpp"
#include "ComponentNameExistsException.hpp"
#include "ComponentNameUnknownException.hpp"
#include "NoChipsetException.hpp"

const std::string nts::Parser::CHIPSET_DECLARATION{".chipsets:"};
const std::string nts::Parser::LINK_DECLARATION{".links:"};

nts::Parser::Parser(const std::string &circuit_file, nts::Circuit &circuit):
    m_file(circuit_file), m_circuit(circuit)
{
    if (!string_endswith(m_file, ".nts"))
        throw nts::FileException(m_file, "Circuit file must have .nts extension");
}

nts::Parser::~Parser() noexcept
{
}

void nts::Parser::parse() const
{
    std::ifstream file(m_file);

    if (!file)
        throw FileException(m_file, "Cannot open file");

    const std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    std::list<nts::Parser::Line> lines;
    readBuffer(buffer, lines);
    initFactory(lines);
    if (m_circuit.empty())
        throw nts::NoChipsetException();
}

void nts::Parser::readBuffer(const std::string &buffer, std::list<nts::Parser::Line> &lines) const noexcept
{
    std::vector<std::string> splitted_buffer = string_split_by_delimiters(buffer, "\r\n", true);
    std::size_t index = 0;

    for (auto &line : splitted_buffer) {
        ++index;
        line = line.substr(0, line.find('#'));
        trim_trailing_whitespace(line);
        if (!line.empty())
            lines.push_back(nts::Parser::Line{.index = index, .content = line});
    }
}

void nts::Parser::initFactory(std::list<nts::Parser::Line> &lines) const
{
    if (lines.empty())
        throw nts::FileException(m_file, "There is no instructions inside file");
    if (lines.front().content.compare(CHIPSET_DECLARATION) != 0)
        throw nts::SyntaxException(lines.front().index, "The first instruction must be the chipsets declaration");

    bool chipset_declared = false;
    bool links_declared = false;
    std::vector<std::string> line_tab;
    nts::Parser::Declaration declaration = nts::Parser::CHIPSETS;
    const std::unordered_map<nts::Parser::Declaration, void (nts::Parser::*)(std::size_t, const std::vector<std::string> &) const> initializer{
        {nts::Parser::CHIPSETS, &nts::Parser::initChipset},
        {nts::Parser::LINKS, &nts::Parser::initLink},
    };

    for (const auto &line : lines) {
        if (line.content.compare(CHIPSET_DECLARATION) == 0) {
            if (chipset_declared)
                throw nts::SyntaxException(line.index, "Redeclaration of chipsets");
            chipset_declared = true;
            declaration = nts::Parser::CHIPSETS;
        } else if (line.content.compare(LINK_DECLARATION) == 0) {
            if (links_declared)
                throw nts::SyntaxException(line.index, "Redeclaration of links");
            links_declared = true;
            declaration = nts::Parser::LINKS;
        } else {
            line_tab = string_split_by_delimiters(line.content, " \t\v");
            (this->*initializer.at(declaration))(line.index, line_tab);
        }
    }
}

void nts::Parser::initChipset(std::size_t line_index, const std::vector<std::string> &line_tab) const
{
    if (line_tab.size() != 2)
        throw nts::SyntaxException(line_index, "Chipset declaration must respect this form: type name");

    const std::string &component_type = line_tab[0];
    const std::string &component_name = line_tab[1];

    if (m_circuit.hasComponent(component_name))
        throw nts::ComponentNameExistsException(line_index, component_name);

    try {
        m_circuit.addComponent(component_type, component_name);
    } catch (const nts::BadComponentTypeException &) {
        throw nts::ComponentTypeUnknownException(line_index, component_type);
    }
}

void nts::Parser::initLink(std::size_t line_index, const std::vector<std::string> &line_tab) const
{
    if (line_tab.size() != 2)
        throw nts::SyntaxException(line_index, "Link declaration must respect this form: name1:pin1 name2:pin2");

    const std::vector<std::string> chipset_link1 = string_split_by_delimiters(line_tab[0], ":", true);
    const std::vector<std::string> chipset_link2 = string_split_by_delimiters(line_tab[1], ":", true);

    if (chipset_link1.size() != 2 || chipset_link2.size() != 2)
        throw nts::SyntaxException(line_index, "Link declaration must respect this form: name1:pin1 name2:pin2");

    const std::string &chipset_name1 = chipset_link1[0];
    const std::string &chipset_pin1 = chipset_link1[1];
    const std::string &chipset_name2 = chipset_link2[0];
    const std::string &chipset_pin2 = chipset_link2[1];

    if (!string_is_number(chipset_pin1))
        throw nts::SyntaxException(line_index, "\"" + chipset_pin1 + "\" is not a positive number");
    if (!string_is_number(chipset_pin2))
        throw nts::SyntaxException(line_index, "\"" + chipset_pin2 + "\" is not a positive number");

    std::size_t pin1 = std::strtoul(chipset_pin1.data(), nullptr, 10);
    std::size_t pin2 = std::strtoul(chipset_pin2.data(), nullptr, 10);

    try {
        m_circuit[chipset_name1].setLink(pin1, m_circuit[chipset_name2], pin2);
    } catch (const nts::BadComponentNameException &e) {
        throw nts::ComponentNameUnknownException(line_index, e.what());
    } catch (const nts::BadPinException &e) {
        throw nts::ComponentLinkException(line_index, chipset_name1, e.what());
    }
    try {
        m_circuit[chipset_name2].setLink(pin2, m_circuit[chipset_name1], pin1);
    } catch (const nts::BadPinException &e) {
        throw nts::ComponentLinkException(line_index, chipset_name2, e.what());
    }
}
