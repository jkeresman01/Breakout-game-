#include "headers/Background.h"

#include "headers/GameConstants.h"
#include "headers/ResourceManager.h"

namespace breakout
{

Background::Background()
{
    m_texture.setSmooth(true);
    m_background.setScale(background::SCALE_X, background::SCALE_Y);
    m_background.setTexture(ResourceManager::Instance().getTexture("resources/images/moon.jpg"));
}

void Background::render(sf::RenderWindow &window) const
{
    window.draw(m_background);
}

} // namespace breakout
