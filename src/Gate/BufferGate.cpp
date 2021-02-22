/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** BufferGate
*/

#include "BufferGate.hpp"

nts::BufferGate::BufferGate() noexcept:
    AGate(BufferGateType, 2, {INPUT}, {OUTPUT}),
    m_buffer(nts::UNDEFINED)
{
}

void nts::BufferGate::simulate(std::size_t tick)
{
    if (m_computed && isNextTick(tick))
        m_buffer = compute(INPUT);
    AGate::simulate(tick);
}

nts::Tristate nts::BufferGate::computeOutput(std::size_t pin __attribute__((unused)))
{
    m_computed = true;
    return m_buffer;
}
