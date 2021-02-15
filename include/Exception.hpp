/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-francis.clairicia-rose-claire-josephine
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>
#include <exception>

namespace nts
{
    class Exception: public std::exception {
        public:
            Exception(const std::string &msg) noexcept;

            const char *what() const noexcept final;

        private:
            std::string m_msg;
    };

    class ParserException: public Exception
    {
        public:
            ParserException(const std::string &error_type, std::size_t line, const std::string &error_msg) noexcept;
    };

    class SyntaxException: public ParserException
    {
        public:
            SyntaxException(std::size_t line, const std::string &msg) noexcept;
    };

    class ComponentTypeUnknownException: public ParserException
    {
        public:
            ComponentTypeUnknownException(std::size_t line, const std::string &type) noexcept;
    };

    class ComponentNameUnknownException: public ParserException
    {
        public:
            ComponentNameUnknownException(std::size_t line, const std::string &name) noexcept;
    };

    class ComponentNameExistsException: public ParserException
    {
        public:
            ComponentNameExistsException(std::size_t line, const std::string &name) noexcept;
    };

    class BadComponentTypeException: public Exception
    {
        public:
            BadComponentTypeException(const std::string &type) noexcept;
    };

    class BadComponentName: public Exception
    {
        public:
            BadComponentName(const std::string &component_name) noexcept;
    };

    class BadPinException: public Exception
    {
        public:
            BadPinException(const std::string &component_type, std::size_t non_valid_pin) noexcept;
    };

    class NoChipsetException: public Exception
    {
        public:
            NoChipsetException() noexcept;
    };

    class ConstComponentException: public Exception
    {
        public:
            ConstComponentException(const std::string &msg) noexcept;
    };

    class FileException: public Exception
    {
        public:
            FileException(const std::string &filepath, const std::string &error_msg) noexcept;
    };

    class InputValueException: public Exception
    {
        public:
            InputValueException(const std::string &value) noexcept;
    };

    class ExitException: public Exception
    {
        public:
            ExitException() noexcept;
    };
}

#endif /* !EXCEPTION_HPP_ */
