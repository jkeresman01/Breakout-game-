#include "headers/ResourceManager.h"

#include "headers/Logger.h"

namespace breakout
{

const sf::SoundBuffer &ResourceManager::getSoundBugffer(const std::filesystem::path &filepath)
{
    std::unordered_map<std::string, sf::SoundBuffer>::const_iterator it;
    if (it = m_soundBuffers.find(filepath.string()); it == m_soundBuffers.end())
    {
        loadSoundBuffer(filepath);
        it = m_soundBuffers.find(filepath);
    }
    return it->second;
}

void ResourceManager::loadSoundBuffer(const std::filesystem::path &filepath)
{
    sf::SoundBuffer soundBuffer;
    ;

    if (soundBuffer.loadFromFile(filepath))
    {
        m_textures.emplace(filepath.string(), soundBuffer);
    }
    else
    {
        LOG_ERROR("Failed to load sound buffer from " << filepath.string() << "!");
    }
}

const sf::Texture &ResourceManager::getTexture(const std::filesystem::path &filepath)
{
    std::unordered_map<std::string, sf::Texture>::const_iterator it;
    if (it = m_textures.find(filepath.string()); it == m_textures.end())
    {
        loadTexture(filepath);
        it = m_textures.find(filepath);
    }
    return it->second;
}

void ResourceManager::loadTexture(const std::filesystem::path &filepath)
{
    sf::Texture texture;

    if (texture.loadFromFile(filepath))
    {
        m_textures.emplace(filepath.string(), texture);
    }
    else
    {
        LOG_ERROR("Failed to load texture from " << filepath.string() << "!");
    }
}

ResourceManager &ResourceManager::Instance()
{
    static ResourceManager instance;
    return instance;
}

} // namespace breakout
