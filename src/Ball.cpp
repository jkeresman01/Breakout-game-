#include "headers/Ball.h"

#include "headers/GameConstants.h"

#include <list>

namespace breakout
{

Ball::Ball() : m_velocity(ball::VELOCITY, -ball::VELOCITY)
{
    m_ball.setRadius(ball::RADIUS);
    m_ball.setFillColor(sf::Color::White);
    reset();
}

void Ball::update(Paddle &paddle, std::list<Brick> &bricks)
{
    m_ball.move(m_velocity);

    bool isBallOnLeftBorder = m_ball.getPosition().x < 0;
    bool isBallOnRightBorder = m_ball.getPosition().x + m_ball.getRadius() * 2 > screen::WIDTH;

    if (isBallOnLeftBorder or isBallOnRightBorder)
    {
        m_velocity.x = -m_velocity.x;
    }

    bool isBallOnTopBorder = m_ball.getPosition().y < 0;
    bool isBallIntersactingPaddle = m_ball.getGlobalBounds().intersects(paddle.getBounds());

    if (isBallOnTopBorder or isBallIntersactingPaddle)
    {
        m_velocity.y = -m_velocity.y;
    }

    std::list<Brick>::iterator it = bricks.begin();
    while (it != bricks.end())
    {
        if (m_ball.getGlobalBounds().intersects(it->getBounds()))
        {
            m_velocity.y = -m_velocity.y;
            it = bricks.erase(it);
        }
        else
        {
            ++it;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        start();
    }

    bool isGameOver = m_ball.getPosition().y > screen::HEIGHT;
    if (isGameOver)
    {
        reset();
    }
}

void Ball::render(sf::RenderWindow &window)
{
    window.draw(m_ball);
}

void Ball::start()
{
    m_velocity = {ball::VELOCITY, -ball::VELOCITY};
}

void Ball::reset()
{
    m_ball.setPosition(screen::WIDTH / 2 - m_ball.getRadius(),
                       screen::HEIGHT / 2 - m_ball.getRadius());
    m_velocity = {0, 0};
}

} // namespace breakout
