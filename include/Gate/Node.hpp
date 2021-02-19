/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Node
*/

#ifndef NODE_HPP_
#define NODE_HPP_

#include "TwoInputsGate.hpp"

namespace nts
{
    class Node: public nts::TwoInputsGate {
        public:
            enum Pin
            {
                INPUT1 = 1,
                INPUT2 = 2,
                OUTPUT = 3
            };

        public:
            Node() noexcept;
            nts::Tristate operation(nts::Tristate a, nts::Tristate b) const final;
    };
}

#endif /* !NODE_HPP_ */
