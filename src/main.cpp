/*
** EPITECH PROJECT, 2021
** nanotekspice
** File description:
** main
*/

#include <iostream>
#include <cstring>
#include "CLINanoTekSpice.hpp"
#include "Exception.hpp"
#include "Args.hpp"
#include "constants.hpp"

namespace
{
    std::unique_ptr<nts::NanoTekSpice> make_interface(const Args &args)
    {
        std::unique_ptr<nts::NanoTekSpice> interface;

        if (args.graphic) {
            /* TODO */
        } else {
            std::unique_ptr<nts::CLINanoTekSpice> cli = std::make_unique<nts::CLINanoTekSpice>(args.nts_file);
            if (!(args.default_command_file.empty()))
                cli->runScript(args.default_command_file);
            interface = std::move(cli);
        }

        return interface;
    }
} // namespace


int main(int ac, char * const *av)
{
    Args args;

    try {
        args = Args::parse(ac, av);
    } catch (const Args::Exception &exception) {
        std::cerr << exception.what() << '\n';
        return EPITECH_EXIT_FAILURE;
    }

    int output = EPITECH_EXIT_SUCCESS;

    try {
        std::unique_ptr<nts::NanoTekSpice> interface = make_interface(args);
        interface->run();
    } catch (const nts::Exception &e) {
        std::cerr << e.what() << '\n';
        output = EPITECH_EXIT_FAILURE;
    }

    return output;
}
