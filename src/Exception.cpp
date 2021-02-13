/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#include "Exception.hpp"

nts::Exception::Exception(const std::string &msg) noexcept: m_msg(msg)
{
}

const char *nts::Exception::what() const noexcept
{
    return m_msg.c_str();
}

nts::ParserException::ParserException(const std::string &error_type, std::size_t line, const std::string &error_msg) noexcept:
    Exception(error_type + " on line " + std::to_string(line) + ": " + error_msg)
{
}

nts::SyntaxException::SyntaxException(std::size_t line, const std::string &msg) noexcept:
    ParserException("Syntax error", line, msg)
{
}

nts::ComponentTypeUnknownException::ComponentTypeUnknownException(std::size_t line, const std::string &type) noexcept:
    ParserException("Component type error", line, "Unknown component type \"" + type + "\"")
{
}

nts::ComponentNameUnknownException::ComponentNameUnknownException(std::size_t line, const std::string &name) noexcept:
    ParserException("Component name error", line, "Unknown component name \"" + name + "\"")
{
}

nts::ComponentNameExistsException::ComponentNameExistsException(std::size_t line, const std::string &name) noexcept:
    ParserException("Component name error", line, "\"" + name + "\" component already exists")
{
}

nts::BadLinkException::BadLinkException(const std::string &component_name, const std::string &why) noexcept:
    Exception("Cannot set link for component \"" + component_name + "\": " + why)
{
}

nts::BadPinException::BadPinException(const std::string &component_name, std::size_t non_valid_pin) noexcept:
    Exception("\"" + component_name + "\" does not have pin " + std::to_string(non_valid_pin))
{
}

nts::GateInputException::GateInputException(const std::string &msg) noexcept:
    Exception("Gate inputs error: " + msg)
{
}

nts::NoChipsetException::NoChipsetException() noexcept: Exception("No chipset in the circuit")
{
}

nts::FileException::FileException(const std::string &filepath, const std::string &error_msg) noexcept:
    Exception(filepath + ": " + error_msg)
{
}

nts::InputValueException::InputValueException(const std::string &value) noexcept:
    Exception("Unknown input value \"" + value + "\"")
{
}
