/*
** EPITECH PROJECT, 2021
** OOP_tekspice_2020
** File description:
** test_Parser
*/

#include <criterion/criterion.h>
#include "Parser.hpp"
#include "FileException.hpp"
#include "NoChipsetException.hpp"
#include "SyntaxException.hpp"
#include "BadComponentNameException.hpp"
#include "ComponentNameExistsException.hpp"
#include "ComponentNameUnknownException.hpp"
#include "ComponentTypeUnknownException.hpp"
#include "ComponentLinkException.hpp"

Test(Parser, read_a_nts_file)
{
    nts::Circuit circuit;

    cr_assert_none_throw((circuit = nts::Parser::parse("tests/.nts/input_output.nts")));
    cr_assert_not(circuit.empty());
    cr_assert_no_throw(circuit["in"], nts::BadComponentNameException);
    cr_assert_no_throw(circuit["out"], nts::BadComponentNameException);
}

Test(Parser, throw_if_file_has_not_nts_extension)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/file")), nts::FileException);
}

Test(Parser, throw_if_file_not_exists)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("./unknown.nts")), nts::FileException);
}

Test(Parser, throw_if_file_is_empty)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/empty.nts")), nts::FileException);
}

Test(Parser, throw_if_file_is_not_empty_but_there_is_no_instructions_inside)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/no_instructions.nts")), nts::FileException);
}

Test(Parser, throw_if_there_is_no_chipsets_in_circuit)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/no_chipsets.nts")), nts::NoChipsetException);
    cr_assert(circuit.empty());
}

Test(Parser, throw_if_chipsets_are_declared_after_links)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_before_chipsets.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_chipsets_are_redeclared)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/redeclaration_chipsets.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_links_are_redeclared)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/redeclaration_links.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_there_is_a_syntax_error_in_chipset_declaration_1)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/chipset_syntax_error1.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_there_is_a_syntax_error_in_chipset_declaration_2)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/chipset_syntax_error2.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_a_component_name_is_already_used)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/chipset_name_exists.nts")), nts::ComponentNameExistsException);
}

Test(Parser, throw_if_a_component_type_does_not_exists)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/chipset_type_unknown.nts")), nts::ComponentTypeUnknownException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_1)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_syntax_error1.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_2)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_syntax_error2.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_3)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_syntax_error3.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_4)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_syntax_error4.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_5)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_syntax_error5.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_6)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_syntax_error6.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_link_pin_is_not_a_number_1)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_pin_not_number1.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_link_pin_is_not_a_number_2)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_pin_not_number2.nts")), nts::SyntaxException);
}

Test(Parser, throw_if_a_component_name_does_not_exists)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_name_unknown.nts")), nts::ComponentNameUnknownException);
}

Test(Parser, throw_if_link_pin_is_not_assignable_1)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_pin_not_assignable1.nts")), nts::ComponentLinkException);
}

Test(Parser, throw_if_link_pin_is_not_assignable_2)
{
    nts::Circuit circuit;

    cr_assert_throw((circuit = nts::Parser::parse("tests/.nts/error/links_pin_not_assignable2.nts")), nts::ComponentLinkException);
}