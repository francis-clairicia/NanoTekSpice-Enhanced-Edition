/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ResourcesManager
*/

#ifndef RESOURCESMANAGER_HPP_
#define RESOURCESMANAGER_HPP_

#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include "Resources.hpp"

namespace nts
{
    class ResourcesManager
    {
    public:
        static const sf::Texture &loadImage(const std::string &image);
        static const sf::Font &loadFont(const std::string &font);

    private:
        ResourcesManager() noexcept = default;
        ResourcesManager(const ResourcesManager &other) noexcept = delete;
        ResourcesManager(ResourcesManager &&other) noexcept = delete;
        ~ResourcesManager() noexcept = default;

        ResourcesManager &operator=(const ResourcesManager &other) noexcept = delete;
        ResourcesManager &operator=(ResourcesManager &&other) noexcept = delete;

    private:
        static ResourcesManager manager;

    private:
        using TextureMap = std::unordered_map<std::string, sf::Texture>;
        using FontMap = std::unordered_map<std::string, sf::Font>;

    private:
        TextureMap textures;
        FontMap    fonts;
    };
} // namespace nts



#endif /* !RESOURCESMANAGER_HPP_ */
