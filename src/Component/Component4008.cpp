/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Component4008
*/

#include "Component4008.hpp"
#include "SumComponent.hpp"

nts::Component4008::Component4008(): AComponent("4008", 16, {1, 2, 3, 4, 5, 6, 7, 9, 15}, {10, 11, 12, 13, 14})
{
    for (std::size_t index = 0; index < 4; ++index)
        m_components.push_back(std::make_unique<SumComponent>());

    m_components[0]->setLink(1, *this, 7);
    m_components[0]->setLink(2, *this, 6);
    m_components[0]->setLink(3, *this, 9);
    m_components[0]->setLink(4, *(m_components[1]), 3);
    m_components[0]->setLink(5, *this, 10);

    m_components[1]->setLink(1, *this, 5);
    m_components[1]->setLink(2, *this, 4);
    m_components[1]->setLink(3, *(m_components[0]), 4);
    m_components[1]->setLink(4, *(m_components[2]), 3);
    m_components[1]->setLink(5, *this, 11);

    m_components[2]->setLink(1, *this, 3);
    m_components[2]->setLink(2, *this, 2);
    m_components[2]->setLink(3, *(m_components[1]), 4);
    m_components[2]->setLink(4, *(m_components[3]), 3);
    m_components[2]->setLink(5, *this, 12);

    m_components[3]->setLink(1, *this, 1);
    m_components[3]->setLink(2, *this, 15);
    m_components[3]->setLink(3, *(m_components[2]), 4);
    m_components[3]->setLink(4, *this, 14);
    m_components[3]->setLink(5, *this, 13);
}

nts::Component4008::~Component4008()
{
}

void nts::Component4008::simulate(std::size_t ticks __attribute__((unused)))
{
}
