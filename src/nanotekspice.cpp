/*
** EPITECH PROJECT, 2021
** nanotekspice
** File description:
** nanotekspice
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <csignal>
#include <string_view>
#include <unistd.h>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "Exception.hpp"
#include "nanotekspice.hpp"
#include "string_operations.hpp"
#include "constants.hpp"

namespace
{
    const std::unordered_map<nts::Tristate, std::string_view> TRISTATE_TO_STR{
        {nts::FALSE,     "0"},
        {nts::TRUE,      "1"},
        {nts::UNDEFINED, "U"}
    };

    bool command_prompt(std::string &buffer)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, buffer)) {
            if (std::cin.eof() && isatty(STDIN_FILENO))
                std::cout << '\n';
            return false;
        }
        trim_trailing_whitespace(buffer);
        return (!buffer.empty()) ? true : command_prompt(buffer);
    }

    void display_command(nts::Circuit &circuit)
    {
        auto list_inputs = circuit.getInputs();
        auto list_outputs = circuit.getOutputs();

        std::cout << "tick: " << circuit.getTick() << '\n';
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

    void simulate_command(nts::Circuit &circuit)
    {
        circuit.simulate();
    }

    void loop_command(nts::Circuit &circuit)
    {
        static bool loop = false;
        auto former_handler = std::signal(SIGINT, [](int){loop = false;});

        loop = true;
        while (loop) {
            simulate_command(circuit);
            display_command(circuit);
        }
        std::signal(SIGINT, former_handler);
    }

    void dump_command(nts::Circuit &circuit)
    {
        circuit.dump();
    }

    void input_value_set(const std::string &input, nts::Circuit &circuit)
    {
        std::vector<std::string> args = string_split_by_delimiters(input, "=", true);

        std::for_each(args.begin(), args.end(), [](std::string &str){trim_trailing_whitespace(str);});
        if (args.size() != 2 || std::any_of(args.begin(), args.end(), [](const std::string &str){return str.empty();})) {
            throw nts::Exception("Invalid syntax");
        }
        circuit.setValue(args[0], args[1]);
    }

    const std::unordered_map<std::string_view, void (*)(nts::Circuit &)> COMMANDS_TAB{
        {"display",  &display_command},
        {"simulate", &simulate_command},
        {"loop",     &loop_command},
        {"dump",     &dump_command},
    };

    void execute_command(nts::Circuit &circuit, const std::string &command)
    {
        try {
            if (command.find('=') != std::string::npos) {
                input_value_set(command, circuit);
            } else {
                const auto &search = COMMANDS_TAB.find(command);
                if (search != COMMANDS_TAB.end())
                    search->second(circuit);
                else
                    std::cerr << "Unknown command \"" << command << "\"" << '\n';
            }
        } catch (const nts::Exception &e){
            std::cerr << e.what() << '\n';
        }
    }

    int cli_mainloop(nts::Circuit &circuit)
    {
        std::string input;
        while (command_prompt(input)) {
            if (input == "exit")
                return EPITECH_EXIT_SUCCESS;
            execute_command(circuit, input);
        }
        return EPITECH_EXIT_SUCCESS;
    }
} // namespace

namespace nts
{
    int nanotekspice(const std::string &circuit_file)
    {
        Circuit circuit = Parser::parse(circuit_file);

        circuit.simulate();
        return cli_mainloop(circuit);
    }

    int nanotekspice(const std::string &circuit_file, const std::string &default_commands_file)
    {
        Circuit circuit = Parser::parse(circuit_file);

        circuit.simulate();
        std::string input;
        std::ifstream commands{default_commands_file};

        if (!commands) {
            std::cerr << "Cannot open '" << default_commands_file << "'\n";
            return EPITECH_EXIT_FAILURE;
        }
        while (std::getline(commands, input)) {
            trim_trailing_whitespace(input);
            if (input.empty())
                continue;
            std::cout << "> " << input << '\n';
            if (input == "exit")
                return EPITECH_EXIT_SUCCESS;
            execute_command(circuit, input);
        }

        return cli_mainloop(circuit);
    }
} // namespace nts

