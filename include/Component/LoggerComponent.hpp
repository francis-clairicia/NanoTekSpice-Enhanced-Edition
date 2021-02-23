/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** LoggerComponent
*/

#ifndef LOGGERCOMPONENT_HPP_
#define LOGGERCOMPONENT_HPP_

#include <fstream>
#include "ACalculationComponent.hpp"

namespace nts
{
    class LoggerComponent: public nts::ACalculationComponent {
        public:
            enum Pin
            {
                BIT0    = 1,
                BIT1    = 2,
                BIT2    = 3,
                BIT3    = 4,
                BIT4    = 5,
                BIT5    = 6,
                BIT6    = 7,
                BIT7    = 8,
                CLOCK   = 9,
                INHIBIT = 10
            };

        public:
            LoggerComponent();
            ~LoggerComponent() noexcept;

        protected:
            void computeOutputs() final;
    };
}

#endif /* !LOGGERCOMPONENT_HPP_ */
