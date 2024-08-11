#include "headers/Background.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace breakout
{
Background::Background()
{
    setTexture("resources/images/moon.jpg");
}

void Background::setTexture(const std::filesystem::path &filepath)
{
    bool isTextureLoadedSuccessfully = m_texture.loadFromFile(filepath.string());

    if (!isTextureLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load texture from: " << filepath.string() << "!")
        return;
    }

    m_texture.setSmooth(true);
    m_background.setScale(background::SCALE_X, background::SCALE_Y);
    m_background.setTexture(m_texture);
}

void Background::render(sf::RenderWindow &window) const
{
    window.draw(m_background);
}

} // namespace breakout
