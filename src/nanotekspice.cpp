/*
** EPITECH PROJECT, 2021
** nanotekspice
** File description:
** nanotekspice
*/

#include <iostream>
#include <algorithm>
#include <csignal>
#include <unistd.h>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "ExitException.hpp"
#include "nanotekspice.hpp"
#include "string_operations.hpp"

static std::istream &command_prompt(std::string &buffer, bool print_command_prompt)
{
    if (print_command_prompt)
        std::cout << "> ";
    return std::getline(std::cin, buffer);
}

static void exit_command(nts::Circuit &circuit __attribute__((unused)), std::size_t &tick __attribute__((unused)))
{
    throw nts::ExitException();
}

static void display_command(nts::Circuit &circuit, std::size_t &tick)
{
    circuit.display(tick);
}

static void simulate_command(nts::Circuit &circuit, std::size_t &tick)
{
    circuit.simulate(++tick);
}

static void loop_command(nts::Circuit &circuit, std::size_t &tick)
{
    static bool loop = false;
    sighandler_t former_handler = signal(SIGINT, [](int){loop = false;});

    loop = true;
    while (loop) {
        simulate_command(circuit, tick);
        display_command(circuit, tick);
    }
    signal(SIGINT, former_handler);
}

static void dump_command(nts::Circuit &circuit, std::size_t &tick __attribute__((unused)))
{
    circuit.dump();
}

static void input_value_set(const std::string &input, nts::Circuit &circuit)
{
    std::vector<std::string> args = string_split_by_delimiters(input, "=", true);

    std::for_each(args.begin(), args.end(), [](std::string &str){trim_trailing_whitespace(str);});
    if (args.size() != 2 || std::any_of(args.begin(), args.end(), [](const std::string &str){return str.empty();})) {
        throw nts::Exception("Invalid syntax");
    }
    circuit.setValueForNextTick(args[0], args[1]);
}

int nts::nanotekspice(const std::string &circuit_file)
{
    nts::Circuit circuit;
    nts::Parser parser{circuit_file, circuit};
    std::string input;
    bool tty = isatty(STDIN_FILENO);
    std::size_t tick = 0;
    std::unordered_map<std::string, void (*)(nts::Circuit &, std::size_t &)> commands{
        {"exit",     &exit_command},
        {"display",  &display_command},
        {"simulate", &simulate_command},
        {"loop",     &loop_command},
        {"dump",     &dump_command},
    };

    parser.parse();
    circuit.simulate(0);
    while (command_prompt(input, tty)) {
        trim_trailing_whitespace(input);
        if (input.empty())
            continue;
        try {
            const auto &search = commands.find(input);
            if (search != commands.end()) {
                search->second(circuit, tick);
            } else if (input.find('=') != std::string::npos){
                input_value_set(input, circuit);
            } else {
                std::cerr << "Unknown command \"" << input << "\"" << std::endl;
            }
        } catch (const nts::ExitException &) {
            break;
        } catch (const nts::Exception &e){
            std::cerr << e.what() << std::endl;
        }
    }
    if (tty && std::cin.eof())
        std::cout << std::endl;
    return (0);
}