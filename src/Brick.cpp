#include "headers/Brick.h"

#include "headers/GameConstants.h"

namespace breakout
{

Brick::Brick(float positionX, float positionY)
{
    m_brick.setSize(sf::Vector2f(brick::WIDTH, brick::HEIGHT));
    m_brick.setOutlineThickness(brick::OUTLINE_THICKNESS);
    m_brick.setOutlineColor(sf::Color::White);
    m_brick.setPosition(positionX, positionY);
    m_brick.setFillColor(sf::Color(233, 217, 247, 90));
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
