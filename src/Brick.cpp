#include "headers/Brick.h"

#include "headers/GameConstants.h"

namespace breakout
{

Brick::Brick(float positionX, float positionY)
{
    m_brick.setSize(sf::Vector2f(brick::WIDTH, brick::HEIGHT));
    m_brick.setFillColor(sf::Color::Green);
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
