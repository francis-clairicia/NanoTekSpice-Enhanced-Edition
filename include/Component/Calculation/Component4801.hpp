/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Component4801
*/

#ifndef COMPONENT4801_HPP_
#define COMPONENT4801_HPP_

#include "ACalculationComponent.hpp"
#include "Memory.hpp"

namespace nts
{
    class Component4801 final: public ACalculationComponent
    {
    public:
        enum PinName
        {
            A7  = 1,
            A6  = 2,
            A5  = 3,
            A4  = 4,
            A3  = 5,
            A2  = 6,
            A1  = 7,
            A0  = 8,
            DQ0 = 9,
            DQ1 = 10,
            DQ2 = 11,
            DQ3 = 13,
            DQ4 = 14,
            DQ5 = 15,
            DQ6 = 16,
            DQ7 = 17,
            CE  = 18,
            OE  = 20,
            WE  = 21,
            A9  = 22,
            A8  = 23
        };

    public:
        Component4801();
        ~Component4801() noexcept override = default;

    private:
        void computeOutputs() final;

        void writeInMemory(std::size_t address) noexcept;
        void readMemory(std::size_t address) noexcept;

    private:
        using RAM = Memory<1024>;

    private:
        RAM m_memory;
    };
} // namespace nts



#endif /* !COMPONENT4801_HPP_ */
