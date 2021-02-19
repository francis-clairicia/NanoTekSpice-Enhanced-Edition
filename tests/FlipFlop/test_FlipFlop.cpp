/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** test_FlipFlop
*/

// #include <criterion/criterion.h>
// #include "FlipFlopComponent.hpp"
// #include "ConstComponent.hpp"

// static nts::Tristate compute(nts::FlipFlopComponent &flipflop,
//                              nts::InputComponent &clock,
//                              nts::InputComponent &data,
//                              nts::InputComponent &reset,
//                              nts::InputComponent &set,
//                              std::size_t output_pin)
// {
//     static std::size_t tick = 0;

//     flipflop.setLink(nts::FlipFlopComponent::CLOCK, clock, 1);
//     flipflop.setLink(nts::FlipFlopComponent::DATA, data, 1);
//     flipflop.setLink(nts::FlipFlopComponent::RESET, reset, 1);
//     flipflop.setLink(nts::FlipFlopComponent::SET, set, 1);
//     flipflop.simulate(++tick);
//     return flipflop.compute(output_pin);
// }

// Test(FlipFlopComponent, Q_truth_table)
// {
//     nts::TrueComponent c_true;
//     nts::FalseComponent c_false;
//     nts::FlipFlopComponent flipflop;

//     cr_assert_eq(compute(flipflop, c_true,  c_false, c_false, c_false, nts::FlipFlopComponent::Q), nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_true,  c_true,  c_false, c_false, nts::FlipFlopComponent::Q), nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_false, c_false, nts::FlipFlopComponent::Q), nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_false, c_false, nts::FlipFlopComponent::Q), nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_true,  c_false, nts::FlipFlopComponent::Q), nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_true,  c_false, c_true,  c_false, nts::FlipFlopComponent::Q), nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_true,  c_false, nts::FlipFlopComponent::Q), nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_true,  c_true,  c_true,  c_false, nts::FlipFlopComponent::Q), nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_false, c_true, nts::FlipFlopComponent::Q),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_true,  c_false, c_false, c_true, nts::FlipFlopComponent::Q),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_false, c_true, nts::FlipFlopComponent::Q),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_true,  c_true,  c_false, c_true, nts::FlipFlopComponent::Q),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_true,  c_true, nts::FlipFlopComponent::Q),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_true,  c_false, c_true,  c_true, nts::FlipFlopComponent::Q),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_true,  c_true, nts::FlipFlopComponent::Q),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_true,  c_true,  c_true,  c_true, nts::FlipFlopComponent::Q),  nts::TRUE);
// }

// Test(FlipFlopComponent, Q_handle_undefined_value)
// {
//     nts::TrueComponent c_true;
//     nts::FalseComponent c_false;
//     nts::InputComponent c_undefined;
//     nts::FlipFlopComponent flipflop;

//     cr_assert_eq(compute(flipflop, c_undefined,  c_false, c_false, c_false, nts::FlipFlopComponent::Q), nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_true,  c_undefined,  c_false, c_false, nts::FlipFlopComponent::Q), nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_undefined, c_false, nts::FlipFlopComponent::Q),  nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_false, c_undefined, nts::FlipFlopComponent::Q),  nts::UNDEFINED);
// }

// Test(FlipFlopComponent, notQ_truth_table)
// {
//     nts::TrueComponent c_true;
//     nts::FalseComponent c_false;
//     nts::FlipFlopComponent flipflop;

//     cr_assert_eq(compute(flipflop, c_true,  c_false, c_false, c_false, nts::FlipFlopComponent::Qn), nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_true,  c_true,  c_false, c_false, nts::FlipFlopComponent::Qn), nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_false, c_false, nts::FlipFlopComponent::Qn), nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_false, c_false, nts::FlipFlopComponent::Qn), nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_true,  c_false, nts::FlipFlopComponent::Qn), nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_true,  c_false, c_true,  c_false, nts::FlipFlopComponent::Qn), nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_true,  c_false, nts::FlipFlopComponent::Qn), nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_true,  c_true,  c_true,  c_false, nts::FlipFlopComponent::Qn), nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_false, c_true, nts::FlipFlopComponent::Qn),  nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_true,  c_false, c_false, c_true, nts::FlipFlopComponent::Qn),  nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_false, c_true, nts::FlipFlopComponent::Qn),  nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_true,  c_true,  c_false, c_true, nts::FlipFlopComponent::Qn),  nts::FALSE);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_true,  c_true, nts::FlipFlopComponent::Qn),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_true,  c_false, c_true,  c_true, nts::FlipFlopComponent::Qn),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_true,  c_true, nts::FlipFlopComponent::Qn),  nts::TRUE);
//     cr_assert_eq(compute(flipflop, c_true,  c_true,  c_true,  c_true, nts::FlipFlopComponent::Qn),  nts::TRUE);
// }

// Test(FlipFlopComponent, notQ_handle_undefined_value)
// {
//     nts::TrueComponent c_true;
//     nts::FalseComponent c_false;
//     nts::InputComponent c_undefined;
//     nts::FlipFlopComponent flipflop;

//     cr_assert_eq(compute(flipflop, c_undefined,  c_false, c_false, c_false, nts::FlipFlopComponent::Qn), nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_true,  c_undefined,  c_false, c_false, nts::FlipFlopComponent::Qn), nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_false, c_false, c_undefined, c_false, nts::FlipFlopComponent::Qn),  nts::UNDEFINED);
//     cr_assert_eq(compute(flipflop, c_false, c_true,  c_false, c_undefined, nts::FlipFlopComponent::Qn),  nts::UNDEFINED);
// }
