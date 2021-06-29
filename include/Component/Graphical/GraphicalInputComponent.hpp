/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** GraphicalInputComponent
*/

#ifndef GRAPHICALINPUTCOMPONENT_HPP_
#define GRAPHICALINPUTCOMPONENT_HPP_

#include "GraphicalIOComponent.hpp"

namespace nts
{
    class GraphicalInputComponent: public GraphicalIOComponent<InputComponent>
    {
    public:
        GraphicalInputComponent();
        ~GraphicalInputComponent() noexcept override = default;

        void update() noexcept override;

    protected:
        void mouseButtonClicked() override;
    };
} // namespace nts

#endif /* !GRAPHICALINPUTCOMPONENT_HPP_ */
