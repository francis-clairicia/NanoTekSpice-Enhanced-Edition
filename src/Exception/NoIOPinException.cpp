/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** NoIOPinException
*/

#include "NoIOPinException.hpp"

namespace nts
{
    NoIOPinException::NoIOPinException(const std::string &component_name) noexcept:
        Exception{component_name + ": This component cannot have pins which are inputs and outputs at the same time."}
    {
    }
} // namespace nts

