/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** nanotekspice
*/

#ifndef NANOTEKSPICE_HPP_
#define NANOTEKSPICE_HPP_

#include <string>

namespace nts
{
    int nanotekspice(const std::string &circuit_file);
    int nanotekspice(const std::string &circuit_file, const std::string &default_commands_file);
}

#endif /* !NANOTEKSPICE_HPP_ */
