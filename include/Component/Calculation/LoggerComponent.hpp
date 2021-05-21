/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** LoggerComponent
*/

#ifndef LOGGERCOMPONENT_HPP_
#define LOGGERCOMPONENT_HPP_

#include <fstream>
#include "ACalculationComponent.hpp"

namespace nts
{
    class LoggerComponent final: public ACalculationComponent
    {
    public:
        enum PinName
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
        ~LoggerComponent() noexcept override;

    private:
        void computeOutputs() final;

    private:
        std::ofstream m_stream;
    };
}

#endif /* !LOGGERCOMPONENT_HPP_ */
