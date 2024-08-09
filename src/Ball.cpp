#include "headers/Ball.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <list>

namespace breakout
{

Ball::Ball() : m_velocity(0.0f, 0.0f)
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

void Ball::render(sf::RenderWindow &window)
{
    window.draw(m_ball);
}

void Ball::start()
{
    bool isBallMoving = m_velocity.x != 0 or m_velocity.y != 0;
    if(!isBallMoving)
    {
        m_velocity = {0, -ball::VELOCITY_Y_COMPONENT};
    }
}

void Ball::reset()
{
    m_ball.setPosition(screen::WIDTH / 2 - m_ball.getRadius(),
                       screen::HEIGHT / 2 - m_ball.getRadius());
    m_velocity = {0, 0};
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
    if (isBallOnTopBorder)
    {
        m_velocity.y = -m_velocity.y;
    }

    bool isBallIntersactingPaddle = m_ball.getGlobalBounds().intersects(paddle.getBounds());
    if (isBallIntersactingPaddle)
    {
        changeBallTrajectory(paddle);
    }

    checkForBrickHits(bricks);
}

void Ball::checkForBrickHits(std::list<Brick> &bricks)
{
    std::list<Brick>::iterator it;
    for (it = bricks.begin(); it != bricks.end();)
    {
        bool isBallIntersectingBrick = m_ball.getGlobalBounds().intersects(it->getBounds());
        if (isBallIntersectingBrick)
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
}

void Ball::changeBallTrajectory(const Paddle &paddle)
{
    float bounceAngleInRadians = calculateBounceAngleInRadians(paddle);
    float speed = calculateSpeed();

    m_velocity.x = speed * std::sin(bounceAngleInRadians);
    m_velocity.y = -speed * std::cos(bounceAngleInRadians);
}

float Ball::calculateSpeed()
{
    float velocityXcomponent = std::pow(m_velocity.x, 2);
    float velocityYcomponent = std::pow(m_velocity.y, 2);

    return std::sqrt(velocityXcomponent + velocityYcomponent);
}

float Ball::calculateBounceAngleInRadians(const Paddle &paddle)
{
    float relativeIntersectX = calculateRelativeIntersectX(paddle);
    float normalizedRelativeIntersectionX = relativeIntersectX / (paddle::WIDTH / 2.0f);

    return normalizedRelativeIntersectionX * (75 * (M_PI / 180.0f));
}

float Ball::calculateRelativeIntersectX(const Paddle &paddle)
{
    float ballCenterX = m_ball.getPosition().x + m_ball.getRadius();
    float paddleCenterX = paddle.getPosition().x + paddle::WIDTH / 2.0f;

    return ballCenterX - paddleCenterX;
}

sf::Vector2f Ball::getPosition() const
{
    return m_ball.getPosition();
}

float Ball::getRadius() const
{
    return m_ball.getRadius();
}

sf::Vector2f Ball::getVelocity() const
{
    return m_velocity;
}

} // namespace breakout
