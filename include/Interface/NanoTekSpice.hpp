/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** NanoTekSpice
*/

#ifndef NANOTEKSPICE_HPP_
#define NANOTEKSPICE_HPP_

#include <memory>

namespace nts
{
    class NanoTekSpice
    {
    public:
        virtual ~NanoTekSpice() noexcept = default;

        virtual void run() = 0;
    };
} // namespace nts

#endif /* !NANOTEKSPICE_HPP_ */
