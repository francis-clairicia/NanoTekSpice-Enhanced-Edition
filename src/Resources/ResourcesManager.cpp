/*
** EPITECH PROJECT, 2021
** NanoTekSpice-Enhanced-Edition
** File description:
** ResourcesManager
*/

#include <filesystem>
#include "ResourcesManager.hpp"
#include "ResourcesException.hpp"

namespace fs = std::filesystem;

namespace
{
    std::string get_full_path(const std::string &realtive_path)
    {
        fs::path absolute_path = fs::absolute(realtive_path).lexically_normal();

        return absolute_path.string();
    }
} // namespace


namespace nts
{
    ResourcesManager ResourcesManager::manager;

    const sf::Texture &ResourcesManager::loadImage(const std::string &image)
    {
        std::string path = get_full_path(image);
        auto search = manager.textures.find(path);

        if (search != manager.textures.end())
            return search->second;
        
        sf::Texture &new_texture = manager.textures[path];

        if (!new_texture.loadFromFile(path))
            throw ResourcesException{path};
        return new_texture;
    }

    const sf::Font &ResourcesManager::loadFont(const std::string &font)
    {
        std::string path = get_full_path(font);
        auto search = manager.fonts.find(path);

        if (search != manager.fonts.end())
            return search->second;
        
        sf::Font &new_font = manager.fonts[path];

        if (!new_font.loadFromFile(path))
            throw ResourcesException{path};
        return new_font;
    }
} // namespace nts
