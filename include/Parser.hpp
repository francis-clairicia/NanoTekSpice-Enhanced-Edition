/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <list>
#include <vector>
#include "Circuit.hpp"

namespace nts
{
    class Parser
    {
    public:
        struct Line
        {
            std::size_t index;
            std::string content;
        };

        enum Declaration
        {
            CHIPSETS,
            LINKS
        };

    public:
        static const std::string CHIPSET_DECLARATION;
        static const std::string LINK_DECLARATION;

    public:
        Parser(const std::string &circuit_file, Circuit &circuit);
        ~Parser() noexcept = default;

        void parse() const;

    private:
        void readBuffer(const std::string &buffer, std::list<Parser::Line> &lines) const noexcept;
        void initFactory(std::list<Parser::Line> &lines) const;
        void initChipset(std::size_t line_index, const std::vector<std::string> &line_tab) const;
        void initLink(std::size_t line_index, const std::vector<std::string> &line_tab) const;

    private:
        std::string m_file;
        Circuit &m_circuit;
    };
}

#endif /* !PARSER_HPP_ */
