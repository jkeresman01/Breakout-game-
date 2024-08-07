#include "headers/Ball.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

#include <cmath>
#include <list>

namespace breakout
{

Ball::Ball() : m_velocity(ball::VELOCITY_X_COMPONENT, ball::VELOCITY_Y_COMPONENT)
{
    m_ball.setRadius(ball::RADIUS);
    m_ball.setFillColor(sf::Color::Yellow);

    loadSound("resources/sound/brick_hit.wav");
    reset();
}

void Ball::loadSound(const std::filesystem::path &path)
{
    bool isSoundEffectLoadedSuccessfully = m_soundBuffer.loadFromFile(path.string());

    if (!isSoundEffectLoadedSuccessfully)
    {
        LOG_ERROR("Failed to load sound effect from " << path.string() << "!");
        return;
    }

    m_brickHitSoundEffect.setBuffer(m_soundBuffer);
}

void Ball::update(const Paddle &paddle, std::list<Brick> &bricks)
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

    if (isBallOnTopBorder)
    {
        m_velocity.y = -m_velocity.y;
    }

    if (isBallIntersactingPaddle)
    {
        changeBallTrajectory(paddle);
    }

    std::list<Brick>::iterator it = bricks.begin();
    while (it != bricks.end())
    {
        if (m_ball.getGlobalBounds().intersects(it->getBounds()))
        {
            m_velocity.y = -m_velocity.y;
            m_brickHitSoundEffect.play();
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

void Ball::changeBallTrajectory(const Paddle &paddle)
{
    float bounceAngleInRadians = calculateBounceAngle(paddle);
    float speed = calculateSpeed();

    m_velocity.x = speed * std::sin(bounceAngleInRadians);
    m_velocity.y = -speed * std::cos(bounceAngleInRadians);
}

float Ball::calculateRelativeIntersectX(const Paddle &paddle)
{
    float ballCenterX = m_ball.getPosition().x + m_ball.getRadius();
    float paddleCenterX = paddle.getPosition().x + paddle::WIDTH / 2.0f;

    return ballCenterX - paddleCenterX;
}

float Ball::calculateBounceAngle(const Paddle &paddle)
{
    float relativeIntersectX = calculateRelativeIntersectX(paddle);
    float normalizedRelativeIntersectionX = relativeIntersectX / (paddle::WIDTH / 2.0f);

    return normalizedRelativeIntersectionX * (75 * (M_PI / 180.0f));
}

float Ball::calculateSpeed()
{
    float velocityXcomponent = std::pow(m_velocity.x, 2);
    float velocityYcomponent = std::pow(m_velocity.y, 2);

    return std::sqrt(velocityXcomponent + velocityYcomponent);
}

void Ball::render(sf::RenderWindow &window)
{
    window.draw(m_ball);
}

void Ball::start()
{
    m_velocity = {0, ball::VELOCITY_Y_COMPONENT};
}

void Ball::reset()
{
    m_ball.setPosition(screen::WIDTH / 2 - m_ball.getRadius(),
                       screen::HEIGHT / 2 - m_ball.getRadius());
    m_velocity = {0, 0};
}

} // namespace breakout
