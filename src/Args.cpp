/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Args
*/

#include <iostream>
#include <vector>
#include <getopt.h>
#include "Args.hpp"

namespace
{
    const std::vector<option> LONG_OPTIONS{
        option{"help", no_argument, nullptr, 'h'},
        option{"graphic", required_argument, nullptr, 'g'},
        option{"interpret", required_argument, nullptr, 'i'},
        option{nullptr, 0, nullptr, 0}
    };

    constexpr std::string_view SHORT_OPTIONS{"hgi:"};
} // namespace


Args Args::parse(int argc, char *const *argv)
{
    Args args;
    Parser parser{argc, argv};

    parser.parse(args);
    return args;
}

Args::Parser::Parser(int argc, char *const *argv):
    m_argc{argc},
    m_argv{argv}
{
    if (!argv)
        throw Exception{"argv is null."};
    if (!(*argv))
        throw Exception{"argv is empty."};
}

void Args::Parser::parse(Args &args)
{
    parseOptions(args);
    parsePositionals(args);
}

void Args::Parser::printHelp() const noexcept
{
    std::cout << "USAGE:\t" << m_argv[0] << " [-h] [-i FILE] circuit\n"
                 "\n"
                 "OPTIONS:\n"
                 "\t" "-h, --help" "\t\t\t" "Shows this help and exit\n"
                 "\t" "-g, --graphic" "\t\t" "Toogle GUI mode\n"
                 "\n"
                 "CLI OPTIONS:\n"
                 "\t" "-i FILE, --interpret=FILE" "\t" "Executes instructions within FILE before showing the prompt\n"
                 "\n"
                 "POSITIONAL ARGUMENTS:\n"
                 "\t" "circuit" "\t" "Path to a .nts circuit file\n";
}

void Args::Parser::parseOptions(Args &args)
{
    int flag = 0;

    optind = 1;
    opterr = 0;
    while ((flag = getopt_long(m_argc, m_argv, SHORT_OPTIONS.data(), LONG_OPTIONS.data(), nullptr)) != -1) {
        switch (flag)
        {
        case 'h':
            printHelp();
            std::exit(0);
        case 'g':
            if (!(args.default_command_file.empty()))
                throw Exception{"Cannot combine -i and -g options"};
            args.graphic = true;
            break;
        case 'i':
            if (args.graphic)
                throw Exception{"Cannot combine -i and -g options"};
            if (!optarg || *optarg == '\0')
                throw Exception{m_argv[0], 'i', "Argument required."};
            args.default_command_file = optarg;
            break;
        default:
            if (SHORT_OPTIONS.find(optopt) == std::string::npos)
                throw Exception{m_argv[0], static_cast<char>(optopt), "Unknown option."};
            throw Exception{m_argv[0], static_cast<char>(optopt), "Argument required."};
        }
    }
}

void Args::Parser::parsePositionals(Args &args)
{
    int positional_argc = m_argc - optind;
    char *const *positional_argv = m_argv + optind;

    if (positional_argc < 1)
        throw Exception{m_argv[0], "circuit", "Missing argument."};
    if (positional_argc > 1)
        throw Exception{m_argv[0], positional_argv[1], "Unexpected argument."};

    args.nts_file = positional_argv[0];
}

Args::Exception::Exception(std::string message) noexcept:
    m_msg{std::move(message)}
{
}

Args::Exception::Exception(const std::string &binary, const std::string &arg, const std::string &error) noexcept:
    m_msg{binary + ": '" + arg + "': " + error}
{
}

Args::Exception::Exception(const std::string &binary, char option, const std::string &error) noexcept:
    m_msg{binary + ": '-" + option + "': " + error}
{
}

const char *Args::Exception::what() const noexcept
{
    return m_msg.c_str();
}
