#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include <filesystem>
#include <list>

#include "Brick.h"
#include "Paddle.h"

namespace breakout
{

class Ball
{
  public:
    Ball();

    void update(const Paddle &paddle, std::list<Brick> &bricks);
    void render(sf::RenderWindow &window);
    void reset();
    void start();

    sf::Vector2f getPosition() const;
    sf::Vector2f getVelocity() const;
    float getRadius() const;

  private:
    float calculateSpeed();
    float calculateBounceAngleInRadians(const Paddle &paddle);
    float calculateRelativeIntersectX(const Paddle &paddle);

    bool isBallHittingVerticalBorder();
    bool isBallHittingTopBorder();
    bool isBallHittingBottomBorder();
    bool isBallIntersectingPaddle(const Paddle &paddle);

    void changeBallTrajectory(const Paddle &paddle);
    void checkForBrickHits(std::list<Brick> &bricks);

    void loadSound(const std::filesystem::path &path);

  private:
    sf::CircleShape m_ball;
    sf::Vector2f m_velocity;
    sf::SoundBuffer m_soundBuffer;
    sf::Sound m_brickHitSoundEffect;
};

} // namespace breakout
