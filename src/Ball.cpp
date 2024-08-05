#include "headers/Ball.h"

#include "headers/GameConstants.h"

namespace breakout
{

Ball::Ball() : m_velocity(ball::VELOCITY, -ball::VELOCITY)
{
    m_ball.setRadius(ball::RADIUS);
    m_ball.setFillColor(sf::Color::White);
    reset();
}

void Ball::update(Paddle &paddle, std::vector<Brick> &bricks)
{
    m_ball.move(m_velocity);

    if (m_ball.getPosition().x < 0 or
        m_ball.getPosition().x + m_ball.getRadius() * 2 > screen::WIDTH)
    {
        m_velocity.x = -m_velocity.x;
    }

    if (m_ball.getPosition().y < 0)
    {
        m_velocity.y = -m_velocity.y;
    }

    if (m_ball.getGlobalBounds().intersects(paddle.getBounds()))
    {
        m_velocity.y = -m_velocity.y;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        start();
    }

    std::vector<Brick>::iterator it = bricks.begin();
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

    if (m_ball.getPosition().y > screen::HEIGHT)
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
