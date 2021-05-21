/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
#include "ComponentNameOverride.hpp"
#include "ComponentNameUnknownException.hpp"
#include "NoChipsetException.hpp"

namespace nts
{
    Parser::Parser(const std::string &circuit_file, Circuit &circuit):
        m_file{circuit_file}, m_circuit{circuit}
    {
        if (!string_endswith(m_file, FILE_EXTENSION.data()))
            throw FileException(m_file, "Circuit file must have .nts extension");
    }

    Circuit Parser::parse(const std::string &file)
    {
        Circuit c;
        Parser p{file, c};

        p.internalParse();
        return c;
    }

    void Parser::internalParse() const
    {
        std::ifstream file{m_file};

        if (!file)
            throw FileException{m_file, "Cannot open file"};

        std::list<Parser::Line> lines;
        std::string line;

        for (std::size_t index = 1; std::getline(file, line); ++index) {
            line = line.substr(0, line.find('#'));
            trim_trailing_whitespace(line);
            if (!line.empty())
                lines.emplace_back(index, line);
        }
        if (file.bad())
            throw FileException{m_file, "Error while reading file."};

        file.close();

        initFactory(lines);
        if (m_circuit.empty())
            throw NoChipsetException();
    }

    void Parser::initFactory(std::list<Parser::Line> &lines) const
    {
        if (lines.empty())
            throw FileException(m_file, "There is no instructions inside file");
        if (lines.front().content.compare(CHIPSET_DECLARATION) != 0)
            throw SyntaxException(lines.front().index, "The first instruction must be the chipsets declaration");

        Declaration *declaration = nullptr;
        std::unordered_map<std::string_view, Parser::Declaration> initializer{
            {Parser::CHIPSET_DECLARATION, Declaration{"chipsets", &Parser::initChipset}},
            {Parser::LINK_DECLARATION, Declaration{"links", &Parser::initLink}},
        };

        for (const auto &line : lines) {
            auto iterator = initializer.find(line.content);
            if (iterator != initializer.end()) {
                declaration = &iterator->second;
                if (declaration->already_declared)
                    throw SyntaxException(line.index, "Redeclaration of " + declaration->name);
                declaration->already_declared = true;
            } else {
                if (!declaration)
                    throw SyntaxException(line.index, "Declaration outside a specific section.");
                (this->*(declaration->method))(line.index, string_split_by_delimiters(line.content, " \t\v"));
            }
        }
    }

    void Parser::initChipset(std::size_t line_index, std::vector<std::string> line_tab) const
    {
        if (line_tab.size() != 2)
            throw SyntaxException(line_index, "Chipset declaration must respect this form: type name");

        const std::string &component_type = line_tab[0];
        const std::string &component_name = line_tab[1];

        try {
            m_circuit.addComponent(component_type, component_name);
        } catch (const ComponentNameOverride &) {
            throw ComponentNameExistsException(line_index, component_name);
        } catch (const BadComponentTypeException &) {
            throw ComponentTypeUnknownException(line_index, component_type);
        }
    }

    void Parser::initLink(std::size_t line_index, std::vector<std::string> line_tab) const
    {
        if (line_tab.size() != 2)
            throw SyntaxException(line_index, "Link declaration must respect this form: name1:pin1 name2:pin2");

        const std::vector<std::string> chipset_link1 = string_split_by_delimiters(line_tab[0], ":", true);
        const std::vector<std::string> chipset_link2 = string_split_by_delimiters(line_tab[1], ":", true);

        if (chipset_link1.size() != 2 || chipset_link2.size() != 2)
            throw SyntaxException(line_index, "Link declaration must respect this form: name1:pin1 name2:pin2");

        const std::string &chipset_name1 = chipset_link1[0];
        const std::string &chipset_pin1 = chipset_link1[1];
        const std::string &chipset_name2 = chipset_link2[0];
        const std::string &chipset_pin2 = chipset_link2[1];

        if (!string_is_number(chipset_pin1))
            throw SyntaxException(line_index, "\"" + chipset_pin1 + "\" is not a positive number");
        if (!string_is_number(chipset_pin2))
            throw SyntaxException(line_index, "\"" + chipset_pin2 + "\" is not a positive number");

        std::size_t pin1 = std::strtoul(chipset_pin1.data(), nullptr, 10);
        std::size_t pin2 = std::strtoul(chipset_pin2.data(), nullptr, 10);

        try {
            m_circuit[chipset_name1].setLink(pin1, m_circuit[chipset_name2], pin2);
        } catch (const BadComponentNameException &e) {
            throw ComponentNameUnknownException(line_index, e.what());
        } catch (const BadPinException &e) {
            throw ComponentLinkException(line_index, chipset_name1, e.what());
        }
        try {
            m_circuit[chipset_name2].setLink(pin2, m_circuit[chipset_name1], pin1);
        } catch (const BadPinException &e) {
            throw ComponentLinkException(line_index, chipset_name2, e.what());
        }
    }
} // namespace nts
