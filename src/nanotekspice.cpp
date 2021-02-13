/*
** EPITECH PROJECT, 2021
** nanotekspice
** File description:
** nanotekspice
*/

#include <iostream>
#include <list>
#include "ComponentFactory.hpp"
#include "Parser.hpp"
#include "Exception.hpp"
#include "nanotekspice.hpp"

int nts::nanotekspice(const std::string &circuit_file)
{
    nts::ComponentFactory factory;
    nts::Parser parser{circuit_file, factory};

    parser.parse();
    factory.dump();
    return (0);
}