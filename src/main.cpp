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
    output << "USAGE:\t./nanotekspice circuit" << std::endl;
    output << std::endl;
    output << "Positional arguments:" << std::endl;
    output << "\tcircuit\t\tPath to a .nts circuit file" << std::endl;
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
        std::cerr << e.what() << std::endl;
        output = 84;
    }

    return output;
}
