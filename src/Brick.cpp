#include "headers/Brick.h"

#include "headers/GameConstants.h"

namespace breakout
{

Brick::Brick(float positionX, float positionY)
{
    m_brick.setSize(sf::Vector2f(brick::WIDTH, brick::HEIGHT));
    m_brick.setFillColor(sf::Color(233, 217, 247, 90));
    m_brick.setOutlineThickness(1.0f);
    m_brick.setOutlineColor(sf::Color::White);
    m_brick.setPosition(positionX, positionY);
}

void Brick::render(sf::RenderWindow &window)
{
    window.draw(m_brick);
}

sf::FloatRect Brick::getBounds() const
{
    return m_brick.getGlobalBounds();
}

} // namespace breakout
