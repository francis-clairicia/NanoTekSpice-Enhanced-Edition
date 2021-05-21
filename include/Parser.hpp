/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
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
        static inline constexpr std::string_view FILE_EXTENSION{".nts"};
        static inline constexpr std::string_view CHIPSET_DECLARATION{".chipsets:"};
        static inline constexpr std::string_view LINK_DECLARATION{".links:"};

    public:
        ~Parser() noexcept = default;

        static Circuit parse(const std::string &file);

    private:
        struct Line
        {
            Line() noexcept = default;
            Line(std::size_t _index, const std::string &_content): index{_index}, content{_content} {}
            ~Line() noexcept = default;

            std::size_t index = 0L;
            std::string content;
        };

        struct Declaration
        {
            using Initializer = void (Parser::*)(std::size_t, std::vector<std::string>) const;

            Declaration(const std::string &_name, Initializer _method): name{_name}, already_declared{false}, method{_method} {}
            ~Declaration() noexcept = default;

            std::string name;
            bool already_declared;
            Initializer method;
        };

    private:
        Parser(const std::string &circuit_file, Circuit &circuit);
        void internalParse() const;
        void initFactory(std::list<Parser::Line> &lines) const;
        void initChipset(std::size_t line_index, std::vector<std::string> line_tab) const;
        void initLink(std::size_t line_index, std::vector<std::string> line_tab) const;

    private:
        std::string m_file;
        Circuit &m_circuit;
    };
}

#endif /* !PARSER_HPP_ */
