/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>
#include "ComponentFactory.hpp"

namespace nts
{
    class Parser {
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
            Parser(const std::string &circuit_file, nts::ComponentFactory &factory);
            ~Parser();

            void parse();

        private:
            void readBuffer(const std::string &buffer, std::list<nts::Parser::Line> &lines) const noexcept;
            void initFactory(std::list<nts::Parser::Line> &lines);
            void initChipset(std::size_t line_index, std::vector<std::string> &line_tab);
            void initLink(std::size_t line_index, std::vector<std::string> &line_tab);

        private:
            std::string m_file;
            nts::ComponentFactory &m_factory;
    };
}

#endif /* !PARSER_HPP_ */
