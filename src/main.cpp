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

static void print_help(std::ostream &output)
{
    output << "USAGE:\t./nanotekspice circuit" << '\n';
    output << '\n';
    output << "Positional arguments:" << '\n';
    output << "\tcircuit\t\tPath to a .nts circuit file" << '\n';
}

int main(int ac, char const * const *av)
{
    if (ac != 2) {
        print_help(std::cerr);
        return 84;
    }
    if (strcmp(av[1], "-h") == 0) {
        print_help(std::cout);
        return 0;
    }

    int output = 0;

    try {
        output = nts::nanotekspice(av[1]);
    } catch (const nts::Exception &e) {
        std::cerr << e.what() << '\n';
        output = 84;
    }

    return output;
}
