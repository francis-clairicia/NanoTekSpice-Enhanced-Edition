/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** CLINanoTekSpice
*/

#include <iostream>
#include <fstream>
#include <csignal>
#include <unistd.h>
#include "CLINanoTekSpice.hpp"
#include "Parser.hpp"
#include "UnknownCommandException.hpp"
#include "SyntaxException.hpp"
#include "FileException.hpp"
#include "string_operations.hpp"
#include "constants.hpp"

namespace
{
    const std::unordered_map<nts::Tristate, std::string_view> TRISTATE_TO_STR{
        {nts::FALSE,     "0"},
        {nts::TRUE,      "1"},
        {nts::UNDEFINED, "U"}
    };

    bool read_input(std::istream &stream, std::string &buffer, bool print_prompt = true)
    {
        if (print_prompt)
            std::cout << nts::CLINanoTekSpice::PROMPT;
        if (!std::getline(stream, buffer)) {
            return false;
        }
        trim_trailing_whitespace(buffer);
        return (!buffer.empty()) ? true : read_input(stream, buffer);
    }
} // namespace


namespace nts
{
    const CLINanoTekSpice::CommandMap CLINanoTekSpice::COMMANDS_TAB{
        {"exit",     &CLINanoTekSpice::exit},
        {"display",  &CLINanoTekSpice::display},
        {"simulate", &CLINanoTekSpice::simulate},
        {"loop",     &CLINanoTekSpice::loop},
        {"dump",     &CLINanoTekSpice::dump},
    };

    CLINanoTekSpice::CLINanoTekSpice() noexcept:
        m_running{false}
    {
    }

    CLINanoTekSpice::CLINanoTekSpice(const std::string &circuit_file):
        m_circuit{Parser::parse<Circuit>(circuit_file)},
        m_running{false}
    {
    }

    void CLINanoTekSpice::run()
    {
        std::string input;

        if (m_circuit.getTick() == NO_TICKS)
            simulate();
        m_running = true;
        while (m_running && read_input(std::cin, input)) {
            try {
                execute(input);
            } catch (const Exception &exception) {
                std::cerr << exception.what() << '\n';
            }
        }
        m_running = false;
        if (std::cin.eof() && isatty(STDIN_FILENO))
            std::cout << '\n';
    }

    void CLINanoTekSpice::execute(const std::string &command)
    {
        if (command.find('=') != std::string::npos) {
            inputValueSet(command);
        } else {
            auto search = COMMANDS_TAB.find(command);
            if (search == COMMANDS_TAB.end())
                throw UnknownCommandException{command};
            (this->*(search->second))();
        }
    }

    void CLINanoTekSpice::runScript(const std::string &script_file)
    {
        std::string input;
        std::ifstream commands{script_file};

        if (!commands) {
            throw FileException{script_file, "Cannot open file"};
        }
        m_running = true;
        while (m_running && read_input(commands, input, false)) {
            std::cout << PROMPT << input << '\n';
            try {
                execute(input);
            } catch (const Exception &exception) {
                std::cerr << exception.what() << '\n';
                break;
            }
        }
        m_running = false;
    }

    void CLINanoTekSpice::exit()
    {
        m_running = false;
    }

    void CLINanoTekSpice::display()
    {
        Circuit::InputsList list_inputs = m_circuit.getInputs();
        Circuit::OutputsList list_outputs = m_circuit.getOutputs();

        std::cout << "tick: " << m_circuit.getTick() << '\n';
        std::cout << "input(s):" << '\n';
        for (const auto &input : list_inputs) {
            std::cout << std::string(2, ' ') << input.name << ": ";
            std::cout << TRISTATE_TO_STR.at(input.component.getValue()) << '\n';
        }
        std::cout << "output(s):" << '\n';
        for (const auto &output : list_outputs) {
            std::cout << std::string(2, ' ') << output.name << ": ";
            std::cout << TRISTATE_TO_STR.at(output.component.getValue()) << '\n';
        }
    }

    void CLINanoTekSpice::simulate()
    {
        m_circuit.simulate();
    }

    void CLINanoTekSpice::loop()
    {
        static bool loop = false;
        auto former_handler = std::signal(SIGINT, [](int){loop = false;});

        loop = true;
        while (loop) {
            simulate();
            display();
        }
        std::signal(SIGINT, former_handler);
    }

    void CLINanoTekSpice::dump()
    {
        m_circuit.dump();
    }

    void CLINanoTekSpice::inputValueSet(const std::string &input)
    {
        std::vector<std::string> args = string_split_by_delimiters(input, "=", true);

        for (std::string &str : args) {
            trim_trailing_whitespace(str);
            if (str.empty())
                throw SyntaxException(0, "Invalid input set");
        }
        if (args.size() != 2) {
            throw SyntaxException(0, "Invalid input set");
        }
        m_circuit.setValue(args[0], args[1]);
    }
} // namespace nts


