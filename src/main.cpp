/*
** EPITECH PROJECT, 2021
** nanotekspice
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "nanotekspice.hpp"
#include "Exception.hpp"
#include "Args.hpp"
#include "constants.hpp"

int main(int ac, char * const *av)
{
    Args args;

    try {
        args = Args::parse(ac, av);
    } catch (const Args::Exception &exception) {
        std::cerr << exception.what() << '\n';
        return EPITECH_EXIT_FAILURE;
    }

    int output = 0;

    try {
        if (!args.default_command_file.empty())
            output = nts::nanotekspice(args.nts_file, args.default_command_file);
        else
            output = nts::nanotekspice(args.nts_file);
    } catch (const nts::Exception &e) {
        std::cerr << e.what() << '\n';
        output = EPITECH_EXIT_FAILURE;
    }

    return output;
}
