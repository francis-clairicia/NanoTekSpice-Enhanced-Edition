/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Args
*/

#ifndef ARGS_HPP_
#define ARGS_HPP_

#include <exception>
#include <string>

struct Args
{
public:
    Args() = default;
    ~Args() noexcept = default;

public:
    static Args parse(int argc, char *const *argv);

public:
    std::string nts_file;
    std::string default_command_file;

private:
    class Parser
    {
    public:
        Parser(int argc, char *const *argv);

        void parse(Args &args);
        void printHelp() const noexcept;

    private:
        void parseOptions(Args &args);
        void parsePositionals(Args &args);

    private:
        int          m_argc;
        char *const *m_argv;
    };

public:
    class Exception: public std::exception
    {
    public:
        Exception(std::string message) noexcept;
        Exception(const std::string &binary, const std::string &arg, const std::string &error) noexcept;
        Exception(const std::string &binary, char option, const std::string &error) noexcept;
        ~Exception() noexcept override = default;

        const char *what() const noexcept final;

    private:
        std::string m_msg;
    };
};

#endif /* !ARGS_HPP_ */
