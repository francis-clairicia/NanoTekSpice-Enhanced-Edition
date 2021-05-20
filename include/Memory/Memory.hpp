/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** Memory
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <memory>
#include <istream>

namespace nts
{
    template<std::size_t Nm>
    class Memory
    {
    public:
        using Byte = unsigned char;

    public:
        Memory(): m_buffer{std::make_unique<Byte []>(Nm)}
        {
            static_assert(Nm > 0, "Memory buffer cannot be empty.");
        }

        Memory(const Memory &other) noexcept = delete;
        Memory(Memory &&other) noexcept = default;
        ~Memory() noexcept = default;

        constexpr std::size_t size() const noexcept
        {
            return Nm;
        }

        Byte *get() noexcept
        {
            return m_buffer.get();
        }

        const Byte *get() const noexcept
        {
            return m_buffer.get();
        }

        Memory &operator=(const Memory &rhs) noexcept = delete;
        Memory &operator=(Memory &&rhs) noexcept = default;

        Byte &operator[](std::size_t index) noexcept
        {
            return m_buffer[index % Nm];
        }

        const Byte &operator[](std::size_t index) const noexcept
        {
            return m_buffer[index % Nm];
        }

    private:
        std::unique_ptr<Byte []> m_buffer;
    };

    template<std::size_t Nm>
    std::istream &operator>>(std::istream &stream, Memory<Nm> &memory) noexcept
    {
        return stream.read(reinterpret_cast<char *>(memory.get()), Nm);
    }    
} // namespace nts

#endif /* !MEMORY_HPP_ */
