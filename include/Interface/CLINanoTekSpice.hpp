/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** CLINanoTekSpice
*/

#ifndef CLINANOTEKSPICE_HPP_
#define CLINANOTEKSPICE_HPP_

#include <unordered_map>
#include <string_view>
#include "Circuit.hpp"
#include "NanoTekSpice.hpp"

namespace nts
{
    class CLINanoTekSpice: public NanoTekSpice
    {
    public:
        CLINanoTekSpice(const std::string &circuit_file);
        CLINanoTekSpice(const CLINanoTekSpice &other) noexcept = delete;
        CLINanoTekSpice(CLINanoTekSpice &&rhs) noexcept = default;
        ~CLINanoTekSpice() noexcept override = default;

        void run() final;
        void execute(const std::string &command);
        void runScript(const std::string &script_file);

        CLINanoTekSpice &operator=(const CLINanoTekSpice &other) noexcept = delete;
        CLINanoTekSpice &operator=(CLINanoTekSpice &&rhs) noexcept = default;

    public:
        static constexpr std::string_view PROMPT{"> "};

    private:
        using CommandMap = std::unordered_map<std::string_view, void (CLINanoTekSpice::*)()>;

    private:
        static const CommandMap COMMANDS_TAB;

    private:
        void exit();
        void display();
        void simulate();
        void loop();
        void dump();
        void inputValueSet(const std::string &input);

    private:
        Circuit m_circuit;
        bool    m_running;
    };
} // namespace nts


#endif /* !CLINANOTEKSPICE_HPP_ */
