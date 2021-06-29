/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Simulation
*/

#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include <SFML/System/Clock.hpp>
#include "Circuit.hpp"

namespace nts
{
    class Simulation
    {
    public:
        explicit Simulation(Circuit &circuit, unsigned int max_framerate = 0) noexcept;
        ~Simulation() noexcept = default;

        void start() noexcept;
        void stop() noexcept;
        void tick();

        [[nodiscard]] unsigned int getFramerate() const noexcept;
        void setFramerate(unsigned int framerate);
        void increaseFramerate() noexcept;
        void decreaseFramerate() noexcept;

    private:
        bool m_started;
        Circuit &m_circuit;
        unsigned int m_fps;
        unsigned int m_max_fps;
        sf::Clock m_clock;
    };
} // namespace nts


#endif /* !SIMULATION_HPP_ */
