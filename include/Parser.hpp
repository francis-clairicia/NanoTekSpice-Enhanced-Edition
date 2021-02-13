/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include "ComponentFactory.hpp"

namespace nts
{
    class Parser {
        public:
            Parser(const std::string &circuit_file, nts::ComponentFactory &factory);
            ~Parser();

            void parse();

        private:
            std::string m_file;
            nts::ComponentFactory &m_factory;
    };
}

#endif /* !PARSER_HPP_ */
