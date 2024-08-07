#include "headers/Paddle.h"

#include "headers/GameConstants.h"
#include <SFML/System/Vector2.hpp>

namespace breakout
{

Paddle::Paddle() : m_speed(paddle::SPEED)
{
    m_paddle.setSize(sf::Vector2f(paddle::WIDTH, paddle::HEIGHT));
    m_paddle.setFillColor(sf::Color(250, 191, 106, 40));
    m_paddle.setOutlineThickness(4.0f);
    m_paddle.setOutlineColor(sf::Color(250, 191, 106, 180));
    m_paddle.setPosition(paddle::POSITION_X, paddle::POSITION_Y);
}

void Paddle::update()
{
    bool isLefKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);

    if (isLefKeyPressed)
    {
        moveLeft();
    }

    bool isRightKeyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    if (isRightKeyPressed)
    {
        moveRight();
    }
}

void Paddle::moveLeft()
{
    bool isPaddlePositionOnLeftBorder = m_paddle.getPosition().x < 0;

    isPaddlePositionOnLeftBorder ? m_paddle.setPosition(0, m_paddle.getPosition().y)
                                 : m_paddle.move(-m_speed, 0);
}

void Paddle::moveRight()
{
    bool isPaddlePositionOnRightBorder =
        m_paddle.getPosition().x + m_paddle.getSize().x > screen::WIDTH;

    isPaddlePositionOnRightBorder
        ? m_paddle.setPosition(screen::WIDTH - paddle::WIDTH, m_paddle.getPosition().y)
        : m_paddle.move(m_speed, 0);
}

sf::Vector2f Paddle::getPosition() const
{
    return m_paddle.getPosition();
}

void Paddle::render(sf::RenderWindow &window)
{
    window.draw(m_paddle);
}

sf::FloatRect Paddle::getBounds() const
{
    return m_paddle.getGlobalBounds();
}

} // namespace breakout
