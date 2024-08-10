#include "headers/Background.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace breakout
{
Background::Background()
{
    setTexture("resources/images/moon.jpg");
}

void Background::setTexture(const std::filesystem::path &path)
{
    bool isTextureLoadedSuccessfully = m_texture.loadFromFile(path.string());

    if (!isTextureLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load texture from: " << path.string() << "!")
        return;
    }

    m_texture.setSmooth(true);
    m_background.setScale(0.7f, 0.7f);
    m_background.setTexture(m_texture);
}

void Background::render(sf::RenderWindow &window)
{
    window.draw(m_background);
}

} // namespace breakout
