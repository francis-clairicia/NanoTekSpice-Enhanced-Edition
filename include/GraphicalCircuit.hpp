/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalCircuit
*/

#ifndef GRAPHICCIRCUIT_HPP_
#define GRAPHICCIRCUIT_HPP_

#include "Circuit.hpp"
#include "AGraphicalComponent.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

namespace nts
{
    class GUINanoTekSpice;

    class GraphicalCircuit: public Circuit
    {
    public:
        GraphicalCircuit() noexcept = default;
        GraphicalCircuit(const GraphicalCircuit &other) noexcept = delete;
        GraphicalCircuit(GraphicalCircuit &&other) noexcept = default;
        ~GraphicalCircuit() noexcept override = default;

        void addComponent(const std::string &type, const std::string &name) override;

        GraphicalCircuit &operator=(const GraphicalCircuit &other) noexcept = delete;
        GraphicalCircuit &operator=(GraphicalCircuit &&other) noexcept = default;

    private:
        using GraphicalComponents = std::map<std::string, std::unique_ptr<AGraphicalComponent>>;

    private:
        GraphicalComponents m_graphical_components;

    private:
        friend class GUINanoTekSpice;
    };
} // namespace nts


#endif /* !GRAPHICCIRCUIT_HPP_ */
