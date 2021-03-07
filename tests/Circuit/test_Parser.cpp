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
    nts::Parser parser{"tests/.nts/input_output.nts", circuit};

    cr_assert_none_throw(parser.parse());
    cr_assert_not(circuit.empty());
    cr_assert_no_throw(circuit["in"], nts::BadComponentNameException);
    cr_assert_no_throw(circuit["out"], nts::BadComponentNameException);
}

Test(Parser, throw_if_file_has_not_nts_extension)
{
    nts::Circuit circuit;

    cr_assert_throw(nts::Parser("tests/.nts/error/file", circuit), nts::FileException);
}

Test(Parser, throw_if_file_not_exists)
{
    nts::Circuit circuit;
    nts::Parser parser{"./unknown.nts", circuit};

    cr_assert_throw(parser.parse(), nts::FileException);
}

Test(Parser, throw_if_file_is_empty)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/empty.nts", circuit};

    cr_assert_throw(parser.parse(), nts::FileException);
}

Test(Parser, throw_if_file_is_not_empty_but_there_is_no_instructions_inside)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/no_instructions.nts", circuit};

    cr_assert_throw(parser.parse(), nts::FileException);
}

Test(Parser, throw_if_there_is_no_chipsets_in_circuit)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/no_chipsets.nts", circuit};

    cr_assert_throw(parser.parse(), nts::NoChipsetException);
    cr_assert(circuit.empty());
}

Test(Parser, throw_if_chipsets_are_declared_after_links)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_before_chipsets.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_chipsets_are_redeclared)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/redeclaration_chipsets.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_links_are_redeclared)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/redeclaration_links.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_there_is_a_syntax_error_in_chipset_declaration_1)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/chipset_syntax_error1.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_there_is_a_syntax_error_in_chipset_declaration_2)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/chipset_syntax_error2.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_a_component_name_is_already_used)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/chipset_name_exists.nts", circuit};

    cr_assert_throw(parser.parse(), nts::ComponentNameExistsException);
}

Test(Parser, throw_if_a_component_type_does_not_exists)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/chipset_type_unknown.nts", circuit};

    cr_assert_throw(parser.parse(), nts::ComponentTypeUnknownException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_1)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_syntax_error1.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_2)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_syntax_error2.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_3)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_syntax_error3.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_4)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_syntax_error4.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_5)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_syntax_error5.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_a_there_is_a_syntax_error_in_link_declaration_6)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_syntax_error6.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_link_pin_is_not_a_number_1)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_pin_not_number1.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_link_pin_is_not_a_number_2)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_pin_not_number2.nts", circuit};

    cr_assert_throw(parser.parse(), nts::SyntaxException);
}

Test(Parser, throw_if_a_component_name_does_not_exists)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_name_unknown.nts", circuit};

    cr_assert_throw(parser.parse(), nts::ComponentNameUnknownException);
}

Test(Parser, throw_if_link_pin_is_not_assignable_1)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_pin_not_assignable1.nts", circuit};

    cr_assert_throw(parser.parse(), nts::ComponentLinkException);
}

Test(Parser, throw_if_link_pin_is_not_assignable_2)
{
    nts::Circuit circuit;
    nts::Parser parser{"tests/.nts/error/links_pin_not_assignable2.nts", circuit};

    cr_assert_throw(parser.parse(), nts::ComponentLinkException);
}