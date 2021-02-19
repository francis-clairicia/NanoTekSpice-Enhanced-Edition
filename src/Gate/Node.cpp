/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Node
*/

// #include <iostream>
#include "Node.hpp"

nts::Node::Node() noexcept: TwoInputsGate("Node")
{
}

nts::Tristate nts::Node::operation(nts::Tristate a, nts::Tristate b) const
{
    // std::cout << "a: " << a << ", b: " << b << std::endl;
    if (a != nts::UNDEFINED && b != nts::UNDEFINED)
        return static_cast<nts::Tristate>(a || b);
    if (a != nts::UNDEFINED)
        return a;
    if (b != nts::UNDEFINED)
        return b;
    return nts::UNDEFINED;
}