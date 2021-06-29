/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalOutputComponent
*/

#ifndef GRAPHICALOUTPUTCOMPONENT_HPP_
#define GRAPHICALOUTPUTCOMPONENT_HPP_

#include "GraphicalIOComponent.hpp"

namespace nts
{    
    class GraphicalOutputComponent: public GraphicalIOComponent<OutputComponent>
    {
    public:
        GraphicalOutputComponent();
        ~GraphicalOutputComponent() noexcept override = default;

        void update() noexcept override;
    };
} // namespace nts

#endif /* !GRAPHICALOUTPUTCOMPONENT_HPP_ */
