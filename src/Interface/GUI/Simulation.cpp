/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Simulation
*/

#include "Simulation.hpp"

namespace nts
{
    Simulation::Simulation(Circuit &circuit, unsigned int max_framerate) noexcept:
        m_circuit{circuit},
        m_fps{max_framerate},
        m_max_fps{max_framerate}
    {
    }

    void Simulation::start() noexcept
    {
        m_started = true;
        m_clock.restart();
    }

    void Simulation::stop() noexcept
    {
        m_started = false;
    }

    void Simulation::tick()
    {
        if (!m_started)
            return;
        if (m_fps == 0) {
            if (m_max_fps == 0)
                m_circuit.simulate();
            return;
        }

        sf::Int64 required_time = 1000000 / m_fps;

        if (m_clock.getElapsedTime().asMicroseconds() > required_time) {
            m_circuit.simulate();
            m_clock.restart();
        }
    }
} // namespace nts

